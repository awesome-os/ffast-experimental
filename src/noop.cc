
#include "ffast.h"

namespace ffast {

void noop_fastFast(void* p);
v8::CTypeInfo cargsnoop_fast[1] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),

};
v8::CTypeInfo rcnoop_fast = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infonoop_fast = v8::CFunctionInfo(rcnoop_fast, 1, cargsnoop_fast);
v8::CFunction pFnoop_fast = v8::CFunction((const void*)&noop_fastFast, &infonoop_fast);


extern "C" {
void noop () {
}
}

void noop_fastSlow(const FunctionCallbackInfo<Value> &args) {

  noop();
}

void noop_fastFast(void* p) {

  noop();
}

void noop_slowSlow(const FunctionCallbackInfo<Value> &args) {

  noop();
}


void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "noop_fast", &pFnoop_fast, noop_fastSlow);
NODE_SET_METHOD(exports, "noop_slow", noop_slowSlow);
  
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
