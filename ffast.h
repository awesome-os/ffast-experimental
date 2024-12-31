#include <node.h>
#include "v8-fast-api-calls.h"

struct FastApiTypedArray {
  uintptr_t length_;
  void* data;
};

struct FastOneByteString {
  const char* data;
  uint32_t length;
};

struct FastApiArrayBuffer {
  void* data;
  size_t byte_length;
};

namespace ffast {

using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::CFunction;
using v8::FunctionCallback;
using v8::Context;
using v8::FunctionTemplate;
using v8::Value;
using v8::Signature;
using v8::ConstructorBehavior;
using v8::SideEffectType;
using v8::Function;
using v8::String;
using v8::FunctionCallbackInfo;
using v8::Integer;
using v8::CTypeInfo;
using v8::CFunctionInfo;
using v8::ArrayBuffer;
using v8::BackingStore;
using v8::Number;
using v8::NewStringType;

void NODE_SET_FAST_METHOD(Isolate* isolate, Local<Object> 
  exports, const char * name, CFunction* fastCFunc, FunctionCallback slowFunc) {
  Local<Context> context = isolate->GetCurrentContext();
  Local<FunctionTemplate> funcTemplate = FunctionTemplate::New(
    isolate,
    slowFunc,
    Local<Value>(),
    Local<Signature>(),
    0,
    ConstructorBehavior::kThrow,
    SideEffectType::kHasNoSideEffect,
    fastCFunc
  );
  Local<Function> fn = funcTemplate->GetFunction(context).ToLocalChecked();
  exports->Set(
    context,
    String::NewFromUtf8(isolate, name).ToLocalChecked(),
    fn
  ).Check();
}

}
