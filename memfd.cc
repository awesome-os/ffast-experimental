// hello.cc
#include "ffast.h"
#include <sys/mman.h>

namespace ffast {

int32_t memfd_createFast(void* p, struct FastOneByteString* const p0, uint32_t p1);
CTypeInfo cargsmemfd_create[3] = {
  CTypeInfo(CTypeInfo::Type::kV8Value),
  CTypeInfo(CTypeInfo::Type::kSeqOneByteString),
  CTypeInfo(CTypeInfo::Type::kUint32),
};
CTypeInfo rcmemfd_create = CTypeInfo(CTypeInfo::Type::kInt32);
CFunctionInfo infomemfd_create = CFunctionInfo(rcmemfd_create, 3, cargsmemfd_create);
CFunction pFmemfd_create = CFunction((const void*)&memfd_createFast, &infomemfd_create);

void method_memfd_create(const FunctionCallbackInfo<Value>& args) {
  Isolate *isolate = args.GetIsolate();
  String::Utf8Value v0(isolate, args[0]);
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = memfd_create(*v0, v1);
  args.GetReturnValue().Set(rc);
}

int32_t memfd_createFast(void* p, struct FastOneByteString* const p0, uint32_t p1) {
  struct FastOneByteString* const v0 = p0;
  uint32_t v1 = p1;
  return memfd_create(v0->data, v1);
}

void FreeMemory(void* buf, size_t length, void* data) {
  free(buf);
}

void WrapMemory(const FunctionCallbackInfo<Value> &args) {
  Isolate* isolate = args.GetIsolate();
  uint64_t start64 = (uint64_t)Local<Number>::Cast(args[0])->Value();
  uint32_t size = (uint32_t)Local<Integer>::Cast(args[1])->Value();
  void* start = reinterpret_cast<void*>(start64);
  int32_t free_memory = 0;
  if (args.Length() > 2) {
    free_memory = (int32_t)Local<Integer>::Cast(args[2])->Value();
  }
  if (free_memory == 0) {
    std::unique_ptr<BackingStore> backing = ArrayBuffer::NewBackingStore(
        start, size, v8::BackingStore::EmptyDeleter, nullptr);
    Local<ArrayBuffer> ab = ArrayBuffer::New(isolate, std::move(backing));
    args.GetReturnValue().Set(ab);
    return;
  }
  std::unique_ptr<BackingStore> backing = ArrayBuffer::NewBackingStore(
      start, size, FreeMemory, nullptr);
  Local<ArrayBuffer> ab = ArrayBuffer::New(isolate, std::move(backing));
  args.GetReturnValue().Set(ab);
}

void UnwrapMemory(const FunctionCallbackInfo<Value> &args) {
  Local<ArrayBuffer> ab = args[0].As<ArrayBuffer>();
  ab->Detach();
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "memfd_create", &pFmemfd_create, method_memfd_create);
  NODE_SET_METHOD(exports, "wrap_memory", WrapMemory);
  NODE_SET_METHOD(exports, "unwrap_memory", UnwrapMemory);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo 
