const { 
  assert, ptr, mprotect, memcpy, mmap,
  PROT_READ, MAP_PRIVATE, PROT_WRITE, PROT_EXEC, MAP_ANONYMOUS
} = require('./ffast.js')

const handle = new Uint32Array(2)

class Compiler {
  compile (code) {
    if (!code.ptr) ptr(code)
    const address = mmap(0, code.length, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 
      -1, handle)
    assert(address)
    assert(memcpy(address, code.ptr, code.length) === address)
    assert(mprotect(address, code.length, PROT_EXEC | PROT_READ) === 0)
    return address
  }
}

module.exports = { Compiler }
