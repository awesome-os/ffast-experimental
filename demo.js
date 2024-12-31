const { isSea, getRawAsset } = require('node:sea');
const { writeSync } = require('node:fs');
const { foo } = require('./foo.js')

function assert (condition, message, ErrorType = Error) {
  if (!condition) {
    if (message && message.constructor.name === 'Function') {
      throw new ErrorType(message(condition))
    }
    throw new ErrorType(message || "Assertion failed")
  }
  return condition
}

const mod = { exports: {} };
process.dlopen(mod, './build/Release/memfd.node')
const { memfd_create } = mod.exports

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
const { count_avx } = load_binding_from_asset('./build/Release/linecount.node')
const buf = new Uint8Array(2 * 1024 * 1024)
buf[10] = 10
assert(count_avx(buf, 10, 1024) === 1)

pid = assert(getpid())

function bench () {
  for (let i = 0; i < 5; i++) {
    const todo = 2000000
    const start = Date.now()
    for (let i = 0; i < todo; i++) {
      assert(getpid() === pid)
    }
    const elapsed = Date.now() - start
    const rate = todo / (elapsed / 1000)
    console.log(`getpid ${rate}`)
  }
  for (let i = 0; i < 5; i++) {
    const todo = 20000000
    const start = Date.now()
    for (let i = 0; i < todo; i++) {
      assert(count_avx(buf, 10, 1024) === 1)
    }
    const elapsed = Date.now() - start
    const rate = todo / (elapsed / 1000)
    console.log(`count_avx ${rate}`)
  }
}

while (1) bench()
