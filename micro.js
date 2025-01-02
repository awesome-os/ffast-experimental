import { createRequire } from "node:module"
import { Bench } from './lib/bench.js'
import { readFileSync } from 'node:fs'
import { 
  assert, ptr, dlopen, dlsym, wrap_memory, mmap, madvise,
  RTLD_LAZY, RTLD_LOCAL, bind, MAP_PRIVATE, MAP_ANONYMOUS,
  MADV_HUGEPAGE, PROT_READ, PROT_WRITE
} from './lib/ffast.js'

const memory_flags = MAP_ANONYMOUS | MAP_PRIVATE

const dlentry = assert(dlopen('./linecount.so', RTLD_LAZY | RTLD_LOCAL))
const memcount_avx2_ffi = bind(assert(dlsym(dlentry, 'memcount_avx2')), 'u32', ['pointer', 'i32', 'u32'])
const { memcount_avx2 } = createRequire(import.meta.url)('./build/Release/count.node')

const buf = ptr(readFileSync('/dev/shm/test.log'))
const bytes = buf.length
const size = 128 * 1024
const buf_ptr = assert(mmap(0, size, PROT_READ | PROT_WRITE, memory_flags, -1, 0))
assert(madvise(buf_ptr, size, MADV_HUGEPAGE) === 0)
const dest = new Uint8Array(wrap_memory(buf_ptr, size, 0))
dest.set(buf, 0)

const expected = assert(memcount_avx2_ffi(buf_ptr, 10, bytes))
assert(expected === memcount_avx2(buf_ptr, 10, bytes))
console.log(`bytes ${bytes}`)
console.log(`lines ${expected}`)

const runs = 1000000
const bench = new Bench()

while (1) {
  for (let j = 0; j < 5; j++) {
    bench.start('memcount_avx2')
    for (let i = 0; i < runs; i++) {
      assert(memcount_avx2(buf_ptr, 10, bytes) === expected)
    }
    bench.end(runs, bytes)
  }

  for (let j = 0; j < 5; j++) {
    bench.start('memcount_avx2_ffi')
    for (let i = 0; i < runs; i++) {
      assert(memcount_avx2_ffi(buf_ptr, 10, bytes) === expected)
    }
    bench.end(runs, bytes)
  }
}