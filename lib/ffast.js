const ffast = require('../build/Release/ffast.node')

const Types = {
  i8: 1, i16: 2, i32: 3, u8: 4, u16: 5, u32: 6, void: 7, f32: 8, f64: 9,
  u64: 10, i64: 11, iSize: 12, uSize: 13, pointer: 14, buffer: 15, function: 16,
  u32array: 17, bool: 18, string: 19
}

function needs_unwrap (t) {
  switch (t) {
    case Types.buffer:
    case Types.pointer:
    case Types.u32array:
    case Types.u64:
    case Types.i64:
      return true
    default:
      return false
  }
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

function wrap (handle, fn, plen = 0) {
  const call = fn
  const params = (new Array(plen)).fill(0).map((_, i) => `p${i}`).join(', ')
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

function bind (res = 'void', params = [], slow = false, fast_address = 0, slow_address = 0) {
  const state = ptr(new Uint8Array(struct_fastcall_size))
  const dv = new DataView(state.buffer)
  const result = Types[res]
  params = params.map(n => Types[n])
  const maxParam = Math.min(params.length, max_args)
  const slowcall_target = slow_address
  let fast_src
  if (!slow) {
    const fastcall_target = fast_address
    // 0-7:   set the fastcall wrapper pointer to first 64-bit slot in state
    //        this slot is also used to receive result in %rax
    dv.setBigUint64(fastcall_pointer_off, BigInt(fastcall_target), true)
  }
  // 8:     set return type
  dv.setUint8(return_type_off, result)
  // 9:     set length of params
  dv.setUint8(param_length_off, maxParam)
  // 10-39: set param types - max 30 params
  for (let i = 0; i < maxParam; i++) dv.setUint8(param_types_off + i, params[i])
  // 104:    set function call pointer to state->fn slot (for slowcall)
  dv.setBigUint64(slowcall_pointer_off, BigInt(slowcall_target), true)
  // todo: wrap here
  const generated_fun = slow ? bind_slowcall(state.ptr) : 
    bind_fastcall(state.ptr)
  // keep the state alive
  generated_fun._state = state
  return needs_unwrap(result) ? wrap(result_handle, generated_fun, 
    params.length) : generated_fun
}

const handle = new Uint32Array(2)
const dlsym = wrap(handle, ffast.dlsym, 2)
const aligned_alloc = wrap(handle, ffast.aligned_alloc, 2)
const dlopen = wrap(handle, ffast.dlopen, 2)
const memcpy = wrap(handle, ffast.memcpy, 3)
const get_address = wrap(handle, ffast.get_address, 1)
const mmap = wrap(handle, ffast.mmap, 6)
const {
  mprotect, munmap, memfd_create, bind_fastcall,
  bind_slowcall, wrap_memory, unwrap_memory,
  PROT_READ, PROT_WRITE, PROT_EXEC, MAP_PRIVATE, MAP_ANONYMOUS,
  RTLD_LAZY, RTLD_LOCAL, RTLD_NOLOAD,
  struct_fastcall_size
} = ffast
const fastcall_pointer_off = 0
const slowcall_pointer_off = 40 + (32 * 8)
const return_type_off = 8
const param_length_off = 9
const param_types_off = 10
const max_args = 30

module.exports = {
  dlopen, dlsym, memcpy, mmap, wrap, assert, ptr, aligned_alloc,
  mprotect, munmap, memfd_create, bind_fastcall,
  bind_slowcall, get_address, wrap_memory, unwrap_memory,
  PROT_READ, PROT_WRITE, PROT_EXEC, MAP_PRIVATE, MAP_ANONYMOUS,
  RTLD_LAZY, RTLD_LOCAL, RTLD_NOLOAD,
  struct_fastcall_size, bind
}
