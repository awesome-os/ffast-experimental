const { isSea, getRawAsset } = require('node:sea');
const { writeSync } = require('node:fs');

function wrap (handle, fn, plen = 0) {
  const call = fn
  const params = (new Array(plen)).fill(0).map((_, i) => `p${i}`).join(', ')
  // TODO: Number.IsSafeInteger check - return BigInt if not safe
  const f = new Function(
    'handle',
    'call',
    `return function ${fn.name} (${params}) {
    call(${params}${plen > 0 ? ', ' : ''}handle);
    const v = handle[0] + ((2 ** 32) * handle[1])
    return handle[0] + ((2 ** 32) * handle[1]);
  }`,)
  const fun = f(handle, call)
  if (fn.state) fun.state = fn.state
  return fun
}

function ptr (u8) {
  u8.ptr = get_address(u8)
  u8.size = u8.byteLength
  return u8
}

function assert (condition, message, ErrorType = Error) {
  if (!condition) {
    if (message && message.constructor.name === 'Function') {
      throw new ErrorType(message(condition))
    }
    throw new ErrorType(message || "Assertion failed")
  }
  return condition
}

const handle = new Uint32Array(2)
const mod = { exports: {} };
process.dlopen(mod, './build/Release/ffast.node')
const { memfd_create, wrap_memory, bind_fastcall, bind_slowcall } = mod.exports

const get_address = wrap(handle, mod.exports.get_address, 1) 

function load_binding_from_asset(path) {
  if (isSea()) {
    const fd = memfd_create(path, 0);
    const buf = new Uint8Array(getRawAsset(path));
    writeSync(fd, buf);
    const mod = { exports: {} };
    process.dlopen(mod, `/proc/self/fd/${fd}`)
    return mod.exports
  }
  return require(path)
}

const { getpid } = load_binding_from_asset('./build/Release/demo.node')
console.log(Object.getOwnPropertyNames(load_binding_from_asset('./build/Release/demo.node')))
const { count_avx } = load_binding_from_asset('./build/Release/linecount.node')
const { memcount_avx2, memcount_sse } = load_binding_from_asset('./build/Release/count.node')

const buf = new Uint8Array(2 * 1024 * 1024)
buf[10] = 10
assert(count_avx(buf, 10, 1024) === 1)
assert(get_address(buf))
assert(ptr(buf).ptr)
assert(memcount_avx2(buf.ptr, 10, 1024) === 1)
assert(memcount_sse(buf.ptr, 10, 1024) === 1)

pid = assert(getpid())


function bench () {
  for (let i = 0; i < 5; i++) {
    const todo = 2000000
    const start = Date.now()
    for (let i = 0; i < todo; i++) {
      assert(getpid() === pid)
    }
    const elapsed = Date.now() - start
    const rate = Math.floor(todo / (elapsed / 1000))
    console.log(`getpid ${rate}`)
  }
  for (let i = 0; i < 5; i++) {
    const todo = 20000000
    const start = Date.now()
    for (let i = 0; i < todo; i++) {
      assert(count_avx(buf, 10, 1024) === 1)
    }
    const elapsed = Date.now() - start
    const rate = Math.floor(todo / (elapsed / 1000))
    console.log(`count_avx ${rate}`)
  }
  for (let i = 0; i < 5; i++) {
    const todo = 60000000
    const start = Date.now()
    for (let i = 0; i < todo; i++) {
      assert(memcount_avx2(buf.ptr, 10, 1024) === 1)
    }
    const elapsed = Date.now() - start
    const rate = Math.floor(todo / (elapsed / 1000))
    console.log(`memcount_avx2 ${rate}`)
  }
  for (let i = 0; i < 5; i++) {
    const todo = 60000000
    const start = Date.now()
    for (let i = 0; i < todo; i++) {
      assert(memcount_sse(buf.ptr, 10, 1024) === 1)
    }
    const elapsed = Date.now() - start
    const rate = Math.floor(todo / (elapsed / 1000))
    console.log(`memcount_sse ${rate}`)
  }
}

while (1) bench()
