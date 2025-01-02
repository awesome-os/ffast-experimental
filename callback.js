import { spawnSync } from 'node:child_process'
import { lstatSync } from 'node:fs'
import * as ffast from './lib/ffast.js'

function mem () {
  return process.memoryUsage().rss
}

function isFile (path) {
  try {
    return lstatSync(path).isFile()
  } catch (err) {
    return false
  }
}

function real_callback (counter) {
  counter += 1
  if (counter === runs) {
    stop()
    const elapsed = Date.now() - then
    const rate = Math.floor(runs / (elapsed / 1000))
    const ns_iter = Math.floor((elapsed * 1000000) / runs)
    console.log(`${runs} ${AG}in${AD} ${elapsed} ${AG}ns${AD} = ${rate} ${AY}per/sec${AD} ${ns_iter} ${AY}ns/iter${AD} ${mem()} ${AC}rss${AD}`)
    then = Date.now()
    if (--total) {
      process.nextTick(start)
      counter = 0
    }
  }
  return counter
}

function trampoline () {
  u32[4] = real_callback(u32[6])
}

const AD = '\u001b[0m'  // ANSI Default
const AG = '\u001b[32m' // ANSI Green
const AY = '\u001b[33m' // ANSI Yellow
const AC = '\u001b[36m' // ANSI Cyan
const uh = new Uint32Array(2)
const { 
  assert, ptr, dlopen, dlsym, bind, register_callback, wrap, asm, compiler,
  Registers
} = ffast
const { rax, rdi, r15 } = Registers
if (!isFile('./callback.so')) {
  const compiler = 'gcc'
  const args = '-fPIC -O3 -march=native -mtune=native -s -shared -o callback.so callback.c'
  assert(spawnSync(compiler, args.split(' ')).status === 0)
}
const handle = assert(dlopen('./callback.so', 1))
const get_callback_address = wrap(uh, ffast.get_callback_address, 0)
const register_callback_c = bind(assert(dlsym(handle, 'register_callback')), 'void', ['pointer'])
const stop = bind(assert(dlsym(handle, 'stop_callbacks')), 'void', [])
const start = bind(assert(dlsym(handle, 'start_callbacks')), 'void', [], true)
const nArgs = 1
const ctx = ptr(new Uint8Array(((nArgs + 3) * 8)))
const u32 = new Uint32Array(ctx.buffer)
const callback_address = assert(get_callback_address())
register_callback(ctx.ptr, trampoline)
const runs = 30000000
let total = 20

asm.reset()
asm.movabs(ctx.ptr, rax)
asm.movdest(rdi, rax, 24)
asm.movreg(rax, rdi)
asm.movreg(rax, r15)
asm.call(callback_address)
asm.movsrc(r15, rax, 16)
asm.ret()

const wrapper = compiler.compile(asm.bytes())
let then = Date.now()
register_callback_c(wrapper)
start()
