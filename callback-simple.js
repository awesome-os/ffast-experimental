import { 
  assert, ptr, dlopen, dlsym, bind, register_callback, wrap, asm, compiler,
  Registers, RTLD_LOCAL, RTLD_NOW, get_callback_address, sleep, addr, usleep
} from './lib/ffast.js'

const create_handle = () => new Uint32Array(2)
const handle = assert(dlopen('./callback.so', RTLD_LOCAL | RTLD_NOW))

const register = bind(assert(dlsym(handle, 'register_callback')), 'void', 
  ['pointer'])
const once = bind(assert(dlsym(handle, 'callback_once')), 'void', [], true)
const callback_address = assert(wrap(create_handle(), get_callback_address, 0)())

const nArgs = 2
const ctx = ptr(new Uint8Array(((nArgs + 3) * 8)))
const u32 = new Uint32Array(ctx.buffer)

register_callback(ctx.ptr, () => {
  const arg1 = u32[6]
  const arg2 = addr(u32.subarray(8, 12))
  assert(arg2 === callback_ptr)
  const ret = u32[4] = u32[6] + 1
    console.log(`arg 0    (u32)     : ${arg1}`)
    console.log(`arg 1    (pointer) : ${arg2}`)
    console.log(`returns  (u32)     : ${ret}`)
  usleep(1)
  process.nextTick(once)
})

const { rax, rdi, rsi, r15 } = Registers
asm.reset()
asm.movabs(ctx.ptr, rax)
asm.movdest(rdi, rax, 24)
asm.movdest(rsi, rax, 32)
asm.movreg(rax, rdi)
asm.movreg(rax, r15)
asm.call(callback_address)
asm.movsrc(r15, rax, 16)
asm.ret()
const callback_ptr = compiler.compile(asm.bytes())

register(callback_ptr)

  once()
