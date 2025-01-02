
#include "ffast.h"
#include <libtcc.h>

namespace ffast {

using v8::Uint32Array;


void createFast(void* p, struct FastApiTypedArray* const p_ret);
v8::CTypeInfo cargscreate[2] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),

  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rccreate = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infocreate = v8::CFunctionInfo(rccreate, 2, cargscreate);
v8::CFunction pFcreate = v8::CFunction((const void*)&createFast, &infocreate);


void createSlow(const FunctionCallbackInfo<Value> &args) {

  void* rc = tcc_new();
  Local<ArrayBuffer> ab = args[0].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void createFast(void* p, struct FastApiTypedArray* const p_ret) {

  void* r = tcc_new();
  ((void**)p_ret->data)[0] = r;

}

void deleteFast(void* p, void* p0);
v8::CTypeInfo cargsdelete[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rcdelete = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infodelete = v8::CFunctionInfo(rcdelete, 2, cargsdelete);
v8::CFunction pFdelete = v8::CFunction((const void*)&deleteFast, &infodelete);


void deleteSlow(const FunctionCallbackInfo<Value> &args) {
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  tcc_delete(v0);
}

void deleteFast(void* p, void* p0) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  tcc_delete(v0);
}

int32_t set_output_typeFast(void* p, void* p0, int32_t p1);
v8::CTypeInfo cargsset_output_type[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
};
v8::CTypeInfo rcset_output_type = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoset_output_type = v8::CFunctionInfo(rcset_output_type, 3, cargsset_output_type);
v8::CFunction pFset_output_type = v8::CFunction((const void*)&set_output_typeFast, &infoset_output_type);


void set_output_typeSlow(const FunctionCallbackInfo<Value> &args) {
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = tcc_set_output_type(v0, v1);
  args.GetReturnValue().Set(rc);
}

int32_t set_output_typeFast(void* p, void* p0, int32_t p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  int32_t v1 = p1;
  return tcc_set_output_type(v0, v1);
}

void set_optionsFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargsset_options[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcset_options = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoset_options = v8::CFunctionInfo(rcset_options, 3, cargsset_options);
v8::CFunction pFset_options = v8::CFunction((const void*)&set_optionsFast, &infoset_options);


void set_optionsSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  tcc_set_options(v0, *v1);
}

void set_optionsFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  tcc_set_options(v0, v1->data);
}

int32_t add_library_pathFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargsadd_library_path[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcadd_library_path = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoadd_library_path = v8::CFunctionInfo(rcadd_library_path, 3, cargsadd_library_path);
v8::CFunction pFadd_library_path = v8::CFunction((const void*)&add_library_pathFast, &infoadd_library_path);


void add_library_pathSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_library_path(v0, *v1);
  args.GetReturnValue().Set(rc);
}

int32_t add_library_pathFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_library_path(v0, v1->data);
}

int32_t add_libraryFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargsadd_library[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcadd_library = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoadd_library = v8::CFunctionInfo(rcadd_library, 3, cargsadd_library);
v8::CFunction pFadd_library = v8::CFunction((const void*)&add_libraryFast, &infoadd_library);


void add_librarySlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_library(v0, *v1);
  args.GetReturnValue().Set(rc);
}

int32_t add_libraryFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_library(v0, v1->data);
}

int32_t add_include_pathFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargsadd_include_path[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcadd_include_path = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoadd_include_path = v8::CFunctionInfo(rcadd_include_path, 3, cargsadd_include_path);
v8::CFunction pFadd_include_path = v8::CFunction((const void*)&add_include_pathFast, &infoadd_include_path);


void add_include_pathSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_include_path(v0, *v1);
  args.GetReturnValue().Set(rc);
}

int32_t add_include_pathFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_include_path(v0, v1->data);
}

int32_t add_fileFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargsadd_file[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcadd_file = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoadd_file = v8::CFunctionInfo(rcadd_file, 3, cargsadd_file);
v8::CFunction pFadd_file = v8::CFunction((const void*)&add_fileFast, &infoadd_file);


void add_fileSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_file(v0, *v1);
  args.GetReturnValue().Set(rc);
}

int32_t add_fileFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_file(v0, v1->data);
}

int32_t compile_stringFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargscompile_string[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rccompile_string = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infocompile_string = v8::CFunctionInfo(rccompile_string, 3, cargscompile_string);
v8::CFunction pFcompile_string = v8::CFunction((const void*)&compile_stringFast, &infocompile_string);


void compile_stringSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_compile_string(v0, *v1);
  args.GetReturnValue().Set(rc);
}

int32_t compile_stringFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_compile_string(v0, v1->data);
}

int32_t relocateFast(void* p, void* p0);
v8::CTypeInfo cargsrelocate[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rcrelocate = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo inforelocate = v8::CFunctionInfo(rcrelocate, 2, cargsrelocate);
v8::CFunction pFrelocate = v8::CFunction((const void*)&relocateFast, &inforelocate);


void relocateSlow(const FunctionCallbackInfo<Value> &args) {
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  int32_t rc = tcc_relocate(v0);
  args.GetReturnValue().Set(rc);
}

int32_t relocateFast(void* p, void* p0) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  return tcc_relocate(v0);
}

void get_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, struct FastApiTypedArray* const p_ret);
v8::CTypeInfo cargsget_symbol[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcget_symbol = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoget_symbol = v8::CFunctionInfo(rcget_symbol, 4, cargsget_symbol);
v8::CFunction pFget_symbol = v8::CFunction((const void*)&get_symbolFast, &infoget_symbol);


void get_symbolSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  void* rc = tcc_get_symbol(v0, *v1);
  Local<ArrayBuffer> ab = args[2].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void get_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, struct FastApiTypedArray* const p_ret) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  void* r = tcc_get_symbol(v0, v1->data);
  ((void**)p_ret->data)[0] = r;

}

int32_t add_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, void* p2);
v8::CTypeInfo cargsadd_symbol[4] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rcadd_symbol = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoadd_symbol = v8::CFunctionInfo(rcadd_symbol, 4, cargsadd_symbol);
v8::CFunction pFadd_symbol = v8::CFunction((const void*)&add_symbolFast, &infoadd_symbol);


void add_symbolSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  const void* v2 = reinterpret_cast<const void*>((uint64_t)Local<Integer>::Cast(args[2])->Value());
  int32_t rc = tcc_add_symbol(v0, *v1, v2);
  args.GetReturnValue().Set(rc);
}

int32_t add_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, void* p2) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  const void* v2 = reinterpret_cast<const void*>(p2);
  return tcc_add_symbol(v0, v1->data, v2);
}

int32_t output_fileFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargsoutput_file[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcoutput_file = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infooutput_file = v8::CFunctionInfo(rcoutput_file, 3, cargsoutput_file);
v8::CFunction pFoutput_file = v8::CFunction((const void*)&output_fileFast, &infooutput_file);


void output_fileSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_output_file(v0, *v1);
  args.GetReturnValue().Set(rc);
}

int32_t output_fileFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_output_file(v0, v1->data);
}

void list_symbolsFast(void* p, void* p0, void* p1, void* p2);
v8::CTypeInfo cargslist_symbols[4] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rclist_symbols = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infolist_symbols = v8::CFunctionInfo(rclist_symbols, 4, cargslist_symbols);
v8::CFunction pFlist_symbols = v8::CFunction((const void*)&list_symbolsFast, &infolist_symbols);


void list_symbolsSlow(const FunctionCallbackInfo<Value> &args) {
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  void* v1 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[1])->Value());
  void* v2 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[2])->Value());
  tcc_list_symbols(v0, v1, (void (*)(void *ctx, const char *name, const void *val))v2);
}

void list_symbolsFast(void* p, void* p0, void* p1, void* p2) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  void* v1 = reinterpret_cast<void*>(p1);
  void* v2 = reinterpret_cast<void*>(p2);
  tcc_list_symbols(v0, v1, (void (*)(void *ctx, const char *name, const void *val))v2);
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "create", &pFcreate, createSlow);
NODE_SET_FAST_METHOD(isolate, exports, "delete", &pFdelete, deleteSlow);
NODE_SET_FAST_METHOD(isolate, exports, "set_output_type", &pFset_output_type, set_output_typeSlow);
NODE_SET_FAST_METHOD(isolate, exports, "set_options", &pFset_options, set_optionsSlow);
NODE_SET_FAST_METHOD(isolate, exports, "add_library_path", &pFadd_library_path, add_library_pathSlow);
NODE_SET_FAST_METHOD(isolate, exports, "add_library", &pFadd_library, add_librarySlow);
NODE_SET_FAST_METHOD(isolate, exports, "add_include_path", &pFadd_include_path, add_include_pathSlow);
NODE_SET_FAST_METHOD(isolate, exports, "add_file", &pFadd_file, add_fileSlow);
NODE_SET_FAST_METHOD(isolate, exports, "compile_string", &pFcompile_string, compile_stringSlow);
NODE_SET_FAST_METHOD(isolate, exports, "relocate", &pFrelocate, relocateSlow);
NODE_SET_FAST_METHOD(isolate, exports, "get_symbol", &pFget_symbol, get_symbolSlow);
NODE_SET_FAST_METHOD(isolate, exports, "add_symbol", &pFadd_symbol, add_symbolSlow);
NODE_SET_FAST_METHOD(isolate, exports, "output_file", &pFoutput_file, output_fileSlow);
NODE_SET_FAST_METHOD(isolate, exports, "list_symbols", &pFlist_symbols, list_symbolsSlow);
  
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}

