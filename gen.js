function getType (t, rv = false) {
  if (t === 'i8') return 'int8_t'
  if (t === 'i16') return 'int16_t'
  if (t === 'i32') return 'int32_t'
  if (t === 'u8') return 'uint8_t'
  if (t === 'bool') return 'uint8_t'
  if (t === 'u16') return 'uint16_t'
  if (t === 'u32') return 'uint32_t'
  if (t === 'void') return 'void'
  if (t === 'f32') return 'float'
  if (t === 'f64') return 'double'
  if (t === 'i64') return 'int64_t'
  if (t === 'u64') return 'uint64_t'
  if (t === 'isz') return 'intptr_t'
  if (t === 'usz') return 'uintptr_t'
  if (t === 'string') return 'struct FastOneByteString* const'
  if (t === 'buffer') return 'struct FastApiTypedArray* const'
  if (t === 'u32array') return 'struct FastApiTypedArray* const'
  if (rv) return 'void'
  return 'void*'
}

function getFastType (id = '') {
  if (id === 'u8') return 'kUint8'
  if (id === 'bool') return 'kUint8'
  if (id === 'u32') return 'kUint32'
  if (id === 'i32') return 'kInt32'
  if (id === 'pointer') return 'kUint64'
  if (id === 'void') return 'kVoid'
  if (id === 'u64') return 'kUint64'
  if (id === 'i64') return 'kInt64'
  if (id === 'f32') return 'kFloat32'
  if (id === 'f64') return 'kFloat64'
  if (id === 'string') return 'kSeqOneByteString'
  if (id === 'buffer') return 'kUint8, CTypeInfo::SequenceType::kIsTypedArray, CTypeInfo::Flags::kNone'
  if (id === 'u32array') return 'kUint32, CTypeInfo::SequenceType::kIsTypedArray, CTypeInfo::Flags::kNone'
  return 'kVoid'
}

function needsUnwrap (t) {
  if (t === 'u8') return false
  if (t === 'bool') return false
  if (t === 'u32') return false
  if (t === 'i32') return false
  if (t === 'f32') return false
  if (t === 'void') return false
  return true
}

function gen_includes (config) {
  return ['"ffast.h"', ...(config.includes || [])].map(n => `#include ${n}`).join('\n')
}

function gen_handlers (config) {
  const src = []
  for (const name of Object.keys(config.api || {})) {
    const def = config.api[name]
    src.push(`int32_t getpidFast(void* p);
CTypeInfo cargsgetpid[1] = {
  CTypeInfo(CTypeInfo::Type::kV8Value),
};
CTypeInfo rcgetpid = CTypeInfo(CTypeInfo::Type::kInt32);
CFunctionInfo infogetpid = CFunctionInfo(rcgetpid, 1, cargsgetpid);
CFunction pFgetpid = CFunction((const void*)&getpidFast, &infogetpid);

void getpidSlow(const FunctionCallbackInfo<Value> &args) {
  int32_t rc = getpid();
  args.GetReturnValue().Set(rc);
}

int32_t getpidFast(void* p) {
  return getpid();
}

`)
  }
  return src.join('\n')
}

function gen_initializer (config) {
  return `NODE_SET_FAST_METHOD(isolate, exports, "getpid", &pFgetpid, getpidSlow);
  NODE_SET_METHOD(exports, "hello", Hello);
`
}

function get_source (config) {
  const src = `
${gen_includes(config)}

namespace ffast {

${gen_handlers(config)
}
void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  ${gen_initializer(config)}
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
`
  return src
}

const name = process.argv[2]
const config = require(`./${name}.config.js`)
console.log(get_source(config))
