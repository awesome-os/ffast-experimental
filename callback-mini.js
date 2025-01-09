import { 
  assert, ptr, dlopen, dlsym, bind, register_callback, wrap, asm, compiler,
  Registers, RTLD_LOCAL, RTLD_NOW, get_callback_address
} from './lib/ffast.js'

function measure (runs) {
  const now = Date.now()
  console.log(`${Math.floor(((now - then) * 1000000) / runs)} ns/op ${process.memoryUsage().rss} rss`)
  then = now
}

function real_callback () {
  try {
//    throw new Error('Foo')
    if ((u32[4] = u32[6] + 1) === runs) {
      stop()
      measure(runs)
      if (--total) {
        u32[4] = 0
        process.nextTick(start)
      }
    }
  } catch (err) {
    console.log(err.stack)
    stop()
  }
}

const handle = assert(dlopen('./callback.so', RTLD_LOCAL | RTLD_NOW))

const register = bind(assert(dlsym(handle, 'register_callback')), 'void', 
  ['pointer'])
const stop = bind(assert(dlsym(handle, 'stop_callbacks')), 'void', [])
const start = bind(assert(dlsym(handle, 'start_callbacks')), 'void', [], true)

const callback_address = assert(wrap(new Uint32Array(2), get_callback_address, 
  0)())

const nArgs = 1
const ctx = ptr(new Uint8Array(((nArgs + 3) * 8)))
const u32 = new Uint32Array(ctx.buffer)
register_callback(ctx.ptr, real_callback)

const { rax, rdi, r15 } = Registers
asm.reset()
asm.movabs(ctx.ptr, rax)
asm.movdest(rdi, rax, 24)
asm.movreg(rax, rdi)
asm.push(r15)
asm.movreg(rax, r15)
asm.call(callback_address)
asm.movsrc(r15, rax, 16)
asm.pop(r15)
asm.ret()
const callback_ptr = compiler.compile(asm.bytes())

let runs = 30000000
let total = 20
register(callback_ptr)
let then = Date.now()
start()
