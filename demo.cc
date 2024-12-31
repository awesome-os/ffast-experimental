#include "ffast.h"

namespace ffast {

int32_t getpidFast(void* p);
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

void Hello(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(
      isolate, "world", NewStringType::kNormal).ToLocalChecked());
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "getpid", &pFgetpid, getpidSlow);
  NODE_SET_METHOD(exports, "hello", Hello);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo 