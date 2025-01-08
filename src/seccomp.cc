
#include "ffast.h"
#include <seccomp.h>

namespace ffast {

void seccomp_syscall_resolve_num_archFast(void* p, int32_t p0, int32_t p1, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsseccomp_syscall_resolve_num_arch[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcseccomp_syscall_resolve_num_arch = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoseccomp_syscall_resolve_num_arch = v8::CFunctionInfo(rcseccomp_syscall_resolve_num_arch, 4, cargsseccomp_syscall_resolve_num_arch);
v8::CFunction pFseccomp_syscall_resolve_num_arch = v8::CFunction((const void*)&seccomp_syscall_resolve_num_archFast, &infoseccomp_syscall_resolve_num_arch);


void seccomp_initFast(void* p, uint32_t p0, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsseccomp_init[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcseccomp_init = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoseccomp_init = v8::CFunctionInfo(rcseccomp_init, 3, cargsseccomp_init);
v8::CFunction pFseccomp_init = v8::CFunction((const void*)&seccomp_initFast, &infoseccomp_init);


int32_t seccomp_rule_add_exactFast(void* p, void* p0, uint32_t p1, int32_t p2, uint32_t p3);
v8::CTypeInfo cargsseccomp_rule_add_exact[5] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
};
v8::CTypeInfo rcseccomp_rule_add_exact = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoseccomp_rule_add_exact = v8::CFunctionInfo(rcseccomp_rule_add_exact, 5, cargsseccomp_rule_add_exact);
v8::CFunction pFseccomp_rule_add_exact = v8::CFunction((const void*)&seccomp_rule_add_exactFast, &infoseccomp_rule_add_exact);


int32_t seccomp_loadFast(void* p, void* p0);
v8::CTypeInfo cargsseccomp_load[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rcseccomp_load = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoseccomp_load = v8::CFunctionInfo(rcseccomp_load, 2, cargsseccomp_load);
v8::CFunction pFseccomp_load = v8::CFunction((const void*)&seccomp_loadFast, &infoseccomp_load);


void seccomp_releaseFast(void* p, void* p0);
v8::CTypeInfo cargsseccomp_release[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rcseccomp_release = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoseccomp_release = v8::CFunctionInfo(rcseccomp_release, 2, cargsseccomp_release);
v8::CFunction pFseccomp_release = v8::CFunction((const void*)&seccomp_releaseFast, &infoseccomp_release);


int32_t seccomp_syscall_resolve_nameFast(void* p, struct FastOneByteString* const p0);
v8::CTypeInfo cargsseccomp_syscall_resolve_name[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcseccomp_syscall_resolve_name = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoseccomp_syscall_resolve_name = v8::CFunctionInfo(rcseccomp_syscall_resolve_name, 2, cargsseccomp_syscall_resolve_name);
v8::CFunction pFseccomp_syscall_resolve_name = v8::CFunction((const void*)&seccomp_syscall_resolve_nameFast, &infoseccomp_syscall_resolve_name);


using v8::Uint32Array;


void seccomp_syscall_resolve_num_archSlow(const FunctionCallbackInfo<Value> &args) {
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  const char* rc = seccomp_syscall_resolve_num_arch(v0, v1);
  Local<ArrayBuffer> ab = args[2].As<Uint32Array>()->Buffer();
  ((const char**)ab->Data())[0] = rc;
}

void seccomp_syscall_resolve_num_archFast(void* p, int32_t p0, int32_t p1, struct FastApiArrayBufferView* const p_ret) {
  int32_t v0 = p0;
  int32_t v1 = p1;
  const char* r = seccomp_syscall_resolve_num_arch(v0, v1);
  ((const char**)p_ret->data)[0] = r;

}

void seccomp_initSlow(const FunctionCallbackInfo<Value> &args) {
  uint32_t v0 = Local<Integer>::Cast(args[0])->Value();
  scmp_filter_ctx rc = seccomp_init(v0);
  Local<ArrayBuffer> ab = args[1].As<Uint32Array>()->Buffer();
  ((scmp_filter_ctx*)ab->Data())[0] = rc;
}

void seccomp_initFast(void* p, uint32_t p0, struct FastApiArrayBufferView* const p_ret) {
  uint32_t v0 = p0;
  scmp_filter_ctx r = seccomp_init(v0);
  ((scmp_filter_ctx*)p_ret->data)[0] = r;

}

void seccomp_rule_add_exactSlow(const FunctionCallbackInfo<Value> &args) {
  scmp_filter_ctx v0 = reinterpret_cast<scmp_filter_ctx>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  uint32_t v3 = Local<Integer>::Cast(args[3])->Value();
  int32_t rc = seccomp_rule_add_exact(v0, v1, v2, v3);
  args.GetReturnValue().Set(rc);
}

int32_t seccomp_rule_add_exactFast(void* p, void* p0, uint32_t p1, int32_t p2, uint32_t p3) {
  scmp_filter_ctx v0 = reinterpret_cast<scmp_filter_ctx>(p0);
  uint32_t v1 = p1;
  int32_t v2 = p2;
  uint32_t v3 = p3;
  return seccomp_rule_add_exact(v0, v1, v2, v3);
}

void seccomp_loadSlow(const FunctionCallbackInfo<Value> &args) {
  scmp_filter_ctx v0 = reinterpret_cast<scmp_filter_ctx>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  int32_t rc = seccomp_load(v0);
  args.GetReturnValue().Set(rc);
}

int32_t seccomp_loadFast(void* p, void* p0) {
  scmp_filter_ctx v0 = reinterpret_cast<scmp_filter_ctx>(p0);
  return seccomp_load(v0);
}

void seccomp_releaseSlow(const FunctionCallbackInfo<Value> &args) {
  scmp_filter_ctx v0 = reinterpret_cast<scmp_filter_ctx>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  seccomp_release(v0);
}

void seccomp_releaseFast(void* p, void* p0) {
  scmp_filter_ctx v0 = reinterpret_cast<scmp_filter_ctx>(p0);
  seccomp_release(v0);
}

void seccomp_syscall_resolve_nameSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  String::Utf8Value v0(isolate, args[0]);
  int32_t rc = seccomp_syscall_resolve_name(*v0);
  args.GetReturnValue().Set(rc);
}

int32_t seccomp_syscall_resolve_nameFast(void* p, struct FastOneByteString* const p0) {
  struct FastOneByteString* const v0 = p0;
  return seccomp_syscall_resolve_name(v0->data);
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "seccomp_syscall_resolve_num_arch", &pFseccomp_syscall_resolve_num_arch, seccomp_syscall_resolve_num_archSlow);
NODE_SET_FAST_METHOD(isolate, exports, "seccomp_init", &pFseccomp_init, seccomp_initSlow);
NODE_SET_FAST_METHOD(isolate, exports, "seccomp_rule_add_exact", &pFseccomp_rule_add_exact, seccomp_rule_add_exactSlow);
NODE_SET_FAST_METHOD(isolate, exports, "seccomp_load", &pFseccomp_load, seccomp_loadSlow);
NODE_SET_FAST_METHOD(isolate, exports, "seccomp_release", &pFseccomp_release, seccomp_releaseSlow);
NODE_SET_FAST_METHOD(isolate, exports, "seccomp_syscall_resolve_name", &pFseccomp_syscall_resolve_name, seccomp_syscall_resolve_nameSlow);
    NODE_SET_VALUE(isolate, exports, "SCMP_ACT_KILL_PROCESS", Integer::New(isolate, (int32_t)SCMP_ACT_KILL_PROCESS));
  NODE_SET_VALUE(isolate, exports, "SCMP_ACT_KILL_THREAD", Integer::New(isolate, (int32_t)SCMP_ACT_KILL_THREAD));
  NODE_SET_VALUE(isolate, exports, "SCMP_ACT_KILL", Integer::New(isolate, (int32_t)SCMP_ACT_KILL));
  NODE_SET_VALUE(isolate, exports, "SCMP_ACT_TRAP", Integer::New(isolate, (int32_t)SCMP_ACT_TRAP));
  NODE_SET_VALUE(isolate, exports, "SCMP_ACT_NOTIFY", Integer::New(isolate, (int32_t)SCMP_ACT_NOTIFY));
  NODE_SET_VALUE(isolate, exports, "SCMP_ACT_LOG", Integer::New(isolate, (int32_t)SCMP_ACT_LOG));
  NODE_SET_VALUE(isolate, exports, "SCMP_ACT_ALLOW", Integer::New(isolate, (int32_t)SCMP_ACT_ALLOW));
  NODE_SET_VALUE(isolate, exports, "SCMP_ARCH_X86_64", Integer::New(isolate, (int32_t)SCMP_ARCH_X86_64));

}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
