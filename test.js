const { Assembler, Registers } = require('./lib/assembler.js')
const { Compiler } = require('./lib/compiler.js')
const { 
  assert, ptr, dlopen, dlsym, aligned_alloc, wrap_memory, 
  RTLD_LAZY, RTLD_LOCAL, RTLD_NOLOAD,
} = require('./lib/ffast.js')
const { rdi, rsi, rbx, rax } = Registers

function bind_parse (read_buf) {
  if (!read_buf.ptr) ptr(read_buf)
  const handle = assert(dlopen('./pico.so', 1))
  const phr_parse_request_sym = assert(dlsym(handle, 'phr_parse_request2'))
  const request_state_ptr = aligned_alloc(8, state_len)
  const request_state = wrap_memory(request_state_ptr, state_len, 0)

  const dv = new DataView(request_state)
  dv.setBigUint64(0, BigInt(read_buf.ptr), true)

  asm.reset()
  asm.movreg(rsi, rdi)
  asm.movabs(request_state_ptr, rsi)
  asm.jmp(phr_parse_request_sym)
  const fast_addr = compiler.compile(asm.bytes())

  asm.reset()
  asm.push(rbx)
  asm.movreg(rdi, rbx)
  // args start at offset 8 in the ffi context
  asm.movsrc(rbx, rdi, 8)
  asm.movabs(request_state_ptr, rsi)
  asm.call(phr_parse_request_sym)
  // result goes at offset 0
  asm.movdest(rax, rbx, 0)
  asm.pop(rbx)
  asm.ret()
  const slow_addr = compiler.compile(asm.bytes())

  return { parse: bind('i32', ['u32'], false, fast_addr, slow_addr) }
}

function bind_gettime () {
  const vdso_sym = assert(dlsym(assert(dlopen('linux-vdso.so.1', RTLD_LAZY | RTLD_LOCAL | RTLD_NOLOAD)), '__vdso_clock_gettime'))

  asm.reset()
  asm.movabs(CLOCK_BOOTTIME, rdi)
  asm.movabs(timespec.ptr, rsi)
  asm.jmp(vdso_sym)
  const fast_addr = compiler.compile(asm.bytes())

  asm.reset()
  asm.push(rbx)
  asm.movreg(rdi, rbx)
  asm.movabs(CLOCK_BOOTTIME, rdi)
  asm.movabs(timespec.ptr, rsi)
  asm.call(vdso_sym)
  asm.movdest(rax, rbx, 0)
  asm.pop(rbx)
  asm.ret()
  const slow_addr = compiler.compile(asm.bytes())

  return { gettime: bind('i32', [], false, fast_addr, slow_addr) }
}

const asm = new Assembler()
const compiler = new Compiler()

const num_headers = 16
const headers_size = (4 * 8 * num_headers)
const state_len = (6 * 8) + headers_size

const read_buf = ptr(new Uint8Array(16384))
const { parse } = bind_parse(read_buf)

const encoder = new TextEncoder()
const payload = encoder.encode('GET / HTTP/1.1\r\n\r\n')
read_buf.set(payload, 0)
const expected = payload.length
assert(parse(expected) === expected)


const CLOCK_BOOTTIME = 7
const timespec = ptr(new Uint32Array(4))

const { gettime } = bind_gettime()
assert(gettime() === 0)

{
  const runs = 60000000
  for (let i = 0; i < 5; i++) {
    const start = Date.now()
    for (let j = 0; j < runs; j++) {
      assert(parse(expected) === expected)
    }
    const elapsed = Date.now() - start
    const rate = Math.floor(runs / (elapsed / 1000))
    console.log(`parse ${rate}`)
  }
}

{
  const runs = 60000000
  for (let i = 0; i < 5; i++) {
    const start = Date.now()
    for (let j = 0; j < runs; j++) {
      assert(gettime() === 0)
    }
    const elapsed = Date.now() - start
    const rate = Math.floor(runs / (elapsed / 1000))
    console.log(`gettime ${rate}`)
  }
}
