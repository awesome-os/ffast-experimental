import { Bench } from './lib/bench.js'
import { readFileSync } from 'node:fs'
import { 
  assert, ptr, dlopen, dlsym, aligned_alloc, wrap_memory, 
  RTLD_LAZY, RTLD_LOCAL, RTLD_NOLOAD, bind_custom,
  compiler, asm, Registers, bind, MAP_PRIVATE, MAP_ANONYMOUS,
  mmap, madvise, MADV_HUGEPAGE, PROT_READ, PROT_WRITE
} from './lib/ffast.js'

const memory_flags = MAP_ANONYMOUS | MAP_PRIVATE
const { rdi, rsi, rbx, rax, rdx } = Registers

function bind_count_avx (buf_ptr) {
  const handle = assert(dlopen('./linecount.so', RTLD_LAZY | RTLD_LOCAL))
  const memcount_avx2_sym = assert(dlsym(handle, 'memcount_avx2'))

  asm.reset()
  asm.movreg(rsi, rdx)
  asm.movabs(buf_ptr, rdi)
  asm.movabs(10, rsi)
  asm.jmp(memcount_avx2_sym)
  const fast_addr = compiler.compile(asm.bytes())

  asm.reset()
  asm.push(rbx)
  asm.movreg(rdi, rbx)
  asm.movsrc(rbx, rdx, 8)
  asm.movabs(buf_ptr, rdi)
  asm.movabs(10, rsi)
  asm.call(memcount_avx2_sym)
  asm.movdest(rax, rbx, 0)
  asm.pop(rbx)
  asm.ret()
  const slow_addr = compiler.compile(asm.bytes())

  return { memcount_avx2: bind_custom('u32', ['u32'], false, fast_addr, slow_addr) }
}


const file_name = '/dev/shm/test.log'

const buf = ptr(readFileSync(file_name))
const bytes = buf.length

const size = 128 * 1024
const buf_ptr = assert(mmap(0, size, PROT_READ | PROT_WRITE, memory_flags, -1, 0))
assert(madvise(buf_ptr, size, MADV_HUGEPAGE) === 0)
const dest = new Uint8Array(wrap_memory(buf_ptr, size, 0))
dest.set(buf, 0)

const { memcount_avx2 } = bind_count_avx(buf_ptr)

const expected = memcount_avx2(bytes)
const runs = 1000000
console.log(`bytes ${bytes}`)
console.log(`lines ${expected}`)

const bench = new Bench()
for (let j = 0; j < 10; j++) {
  bench.start('memcount_avx2')
  for (let i = 0; i < runs; i++) {
    assert(memcount_avx2(bytes) === expected)
  }
  bench.end(runs, bytes)
}
