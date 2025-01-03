
#include "ffast.h"
#include <sys/mman.h>
#include <dlfcn.h>

namespace ffast {

void dlopenFast(void* p, struct FastOneByteString* const p0, int32_t p1, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsdlopen[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcdlopen = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infodlopen = v8::CFunctionInfo(rcdlopen, 4, cargsdlopen);
v8::CFunction pFdlopen = v8::CFunction((const void*)&dlopenFast, &infodlopen);


void dlsymFast(void* p, void* p0, struct FastOneByteString* const p1, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsdlsym[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcdlsym = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infodlsym = v8::CFunctionInfo(rcdlsym, 4, cargsdlsym);
v8::CFunction pFdlsym = v8::CFunction((const void*)&dlsymFast, &infodlsym);


void aligned_allocFast(void* p, uint32_t p0, uint32_t p1, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsaligned_alloc[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcaligned_alloc = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoaligned_alloc = v8::CFunctionInfo(rcaligned_alloc, 4, cargsaligned_alloc);
v8::CFunction pFaligned_alloc = v8::CFunction((const void*)&aligned_allocFast, &infoaligned_alloc);


int32_t mprotectFast(void* p, void* p0, uint32_t p1, int32_t p2);
v8::CTypeInfo cargsmprotect[4] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
};
v8::CTypeInfo rcmprotect = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infomprotect = v8::CFunctionInfo(rcmprotect, 4, cargsmprotect);
v8::CFunction pFmprotect = v8::CFunction((const void*)&mprotectFast, &infomprotect);


void memcpyFast(void* p, void* p0, void* p1, uint32_t p2, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsmemcpy[5] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcmemcpy = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infomemcpy = v8::CFunctionInfo(rcmemcpy, 5, cargsmemcpy);
v8::CFunction pFmemcpy = v8::CFunction((const void*)&memcpyFast, &infomemcpy);


void mmapFast(void* p, void* p0, uint32_t p1, int32_t p2, int32_t p3, int32_t p4, uint32_t p5, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsmmap[8] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcmmap = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infommap = v8::CFunctionInfo(rcmmap, 8, cargsmmap);
v8::CFunction pFmmap = v8::CFunction((const void*)&mmapFast, &infommap);


int32_t munmapFast(void* p, void* p0, uint32_t p1);
v8::CTypeInfo cargsmunmap[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
};
v8::CTypeInfo rcmunmap = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infomunmap = v8::CFunctionInfo(rcmunmap, 3, cargsmunmap);
v8::CFunction pFmunmap = v8::CFunction((const void*)&munmapFast, &infomunmap);


int32_t memfd_createFast(void* p, struct FastOneByteString* const p0, uint32_t p1);
v8::CTypeInfo cargsmemfd_create[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
};
v8::CTypeInfo rcmemfd_create = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infomemfd_create = v8::CFunctionInfo(rcmemfd_create, 3, cargsmemfd_create);
v8::CFunction pFmemfd_create = v8::CFunction((const void*)&memfd_createFast, &infomemfd_create);





void get_addressFast(void* p, struct FastApiArrayBufferView* const p0, struct FastApiArrayBufferView* const p_ret);
v8::CTypeInfo cargsget_address[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint8, CTypeInfo::SequenceType::kIsTypedArray, CTypeInfo::Flags::kNone),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rcget_address = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infoget_address = v8::CFunctionInfo(rcget_address, 3, cargsget_address);
v8::CFunction pFget_address = v8::CFunction((const void*)&get_addressFast, &infoget_address);





int32_t madviseFast(void* p, void* p0, uint32_t p1, int32_t p2);
v8::CTypeInfo cargsmadvise[4] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
};
v8::CTypeInfo rcmadvise = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infomadvise = v8::CFunctionInfo(rcmadvise, 4, cargsmadvise);
v8::CFunction pFmadvise = v8::CFunction((const void*)&madviseFast, &infomadvise);


void sleepFast(void* p, int32_t p0);
v8::CTypeInfo cargssleep[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
};
v8::CTypeInfo rcsleep = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infosleep = v8::CFunctionInfo(rcsleep, 2, cargssleep);
v8::CFunction pFsleep = v8::CFunction((const void*)&sleepFast, &infosleep);


int32_t usleepFast(void* p, uint32_t p0);
v8::CTypeInfo cargsusleep[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
};
v8::CTypeInfo rcusleep = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infousleep = v8::CFunctionInfo(rcusleep, 2, cargsusleep);
v8::CFunction pFusleep = v8::CFunction((const void*)&usleepFast, &infousleep);


int32_t utf8_lengthFast(void* p, struct FastOneByteString* const p0);
v8::CTypeInfo cargsutf8_length[2] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rcutf8_length = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infoutf8_length = v8::CFunctionInfo(rcutf8_length, 2, cargsutf8_length);
v8::CFunction pFutf8_length = v8::CFunction((const void*)&utf8_lengthFast, &infoutf8_length);


using v8::HandleScope;
using v8::Uint8Array;
using v8::Uint32Array;
using v8::ObjectTemplate;
using v8::TypedArray;
using v8::Global;
using v8::BigInt;
using v8::MaybeLocal;
using v8::TryCatch;

enum FastTypes: int {
  i8 = 1, i16 = 2, i32 = 3, u8 = 4, u16 = 5, u32 = 6, empty = 7, f32 = 8,
  f64 = 9, u64 = 10, i64 = 11, iSize = 12, uSize = 13, pointer = 14,
  buffer = 15, function = 16, u32array = 17, boolean = 18, string = 19
};

struct fastcall {
  void* wrapper;      // 0-7   :   v8 fastcall wrapper function pointer
  uint8_t result;     // 8     :   the type of the result
  uint8_t nparam;     // 9     :   the number of args (max 255) 
  uint8_t param[30];  // 10-39 :   an array of types of the arguments
  uint64_t args[32];  // 40-295:   an array of pointer slots for arguments
                      // these will be filled in dynamically by 
                      // lo::core::SlowCallback for the slow call
                      // and then the slowcall wrapper will shift them from
                      // this structure into regs + stack and make the call
                      // the first slot is reserved for the result
  void* fn;           // 296-303:  the slowcall wrapper function pointer
  uint8_t padding[80]; // 304-383 :   an array of types of the arguments
};

int struct_fastcall_size = sizeof(struct fastcall);

typedef void (*lo_fast_call)(void*);

struct exec_info {
  v8::Global<v8::Function> js_fn;
  v8::Isolate* isolate;
  uint64_t rv;
  int nargs;
};

void lo_callback (exec_info* info) {
  Isolate* isolate = info->isolate;
  HandleScope scope(isolate);
  info->js_fn.Get(isolate)->Call(isolate->GetCurrentContext(), 
    v8::Null(isolate), 0, 0);
//  TryCatch try_catch(isolate);
//  MaybeLocal<Value> result = info->js_fn.Get(isolate)->Call(isolate->GetCurrentContext(), 
//    v8::Null(isolate), 0, 0);
//  if (result.IsEmpty() && try_catch.HasCaught()) {
//    try_catch.ReThrow();
//  }
//  TODO: this needs to return a value
}

inline uint8_t needsunwrap (FastTypes t) {
  if (t == FastTypes::buffer) return 1;
  if (t == FastTypes::u32array) return 1;
  if (t == FastTypes::pointer) return 1;
  if (t == FastTypes::u64) return 1;
  if (t == FastTypes::i64) return 1;
  return 0;
}

void FreeMemory(void* buf, size_t length, void* data) {
  free(buf);
}

CTypeInfo* CTypeFromV8 (uint8_t v8Type) {
  if (v8Type == FastTypes::boolean)
    return new CTypeInfo(CTypeInfo::Type::kBool);
  if (v8Type == FastTypes::i8)
    return new CTypeInfo(CTypeInfo::Type::kInt32);
  if (v8Type == FastTypes::i16)
    return new CTypeInfo(CTypeInfo::Type::kInt32);
  if (v8Type == FastTypes::i32)
    return new CTypeInfo(CTypeInfo::Type::kInt32);
  if (v8Type == FastTypes::u8)
    return new CTypeInfo(CTypeInfo::Type::kUint32);
  if (v8Type == FastTypes::u16)
    return new CTypeInfo(CTypeInfo::Type::kUint32);
  if (v8Type == FastTypes::u32)
    return new CTypeInfo(CTypeInfo::Type::kUint32);
  if (v8Type == FastTypes::f32)
    return new CTypeInfo(CTypeInfo::Type::kFloat32);
  if (v8Type == FastTypes::f64)
    return new CTypeInfo(CTypeInfo::Type::kFloat64);
  if (v8Type == FastTypes::i64)
    return new CTypeInfo(CTypeInfo::Type::kInt64);
  if (v8Type == FastTypes::u64)
    return new CTypeInfo(CTypeInfo::Type::kUint64);
  if (v8Type == FastTypes::iSize)
    return new CTypeInfo(CTypeInfo::Type::kInt64);
  if (v8Type == FastTypes::uSize)
    return new CTypeInfo(CTypeInfo::Type::kUint64);
  if (v8Type == FastTypes::pointer)
    return new CTypeInfo(CTypeInfo::Type::kUint64);
  if (v8Type == FastTypes::function)
    return new CTypeInfo(CTypeInfo::Type::kUint64);
  if (v8Type == FastTypes::string)
    return new CTypeInfo(CTypeInfo::Type::kSeqOneByteString);
  if (v8Type == FastTypes::buffer) {
    return new CTypeInfo(CTypeInfo::Type::kUint8,
      CTypeInfo::SequenceType::kIsTypedArray, CTypeInfo::Flags::kNone);
  }
  if (v8Type == FastTypes::u32array) {
    return new CTypeInfo(CTypeInfo::Type::kUint32,
      CTypeInfo::SequenceType::kIsTypedArray, CTypeInfo::Flags::kNone);
  }
  return new CTypeInfo(CTypeInfo::Type::kVoid);
}

void lo_fastcall (struct fastcall* state) {
  ((lo_fast_call)state->fn)(&state->args);
}

void SlowCallback(const FunctionCallbackInfo<Value> &args) {
  struct fastcall* state = (struct fastcall*)Local<Integer>::Cast(args.Data())->Value();
  if (state->nparam == 0 & state->result == FastTypes::empty) {
    lo_fastcall(state);
    return;
  }
  Isolate* isolate = args.GetIsolate();
  HandleScope scope(isolate);
  int r = 1;
  for (int i = 0; i < state->nparam; i++) {
    switch (state->param[i]) {
      case FastTypes::string:
        {
          String::Utf8Value arg0(isolate, args[i]);
          // todo: fix this - never gets freed
//          state->args[r++] = (uint64_t)*arg0;
          state->args[r++] = (uint64_t)strdup(*arg0);
        }
        break;
      case FastTypes::u32:
        state->args[r++] = (uint32_t)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::u16:
        state->args[r++] = (uint16_t)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::u8:
        state->args[r++] = (uint8_t)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::boolean:
        state->args[r++] = (bool)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::i32:
        state->args[r++] = (int32_t)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::i16:
        state->args[r++] = (int16_t)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::i8:
        state->args[r++] = (int8_t)Local<Integer>::Cast(args[i])->Value();
        break;
      case FastTypes::i64:
      case FastTypes::iSize:
        state->args[r++] = (int64_t)Local<Number>::Cast(args[i])->Value();
        break;
      case FastTypes::u64:
      case FastTypes::pointer:
      case FastTypes::uSize:
        state->args[r++] = (uint64_t)Local<Number>::Cast(args[i])->Value();
        break;
      case FastTypes::buffer:
        {
          Local<Uint8Array> u8 = args[i].As<Uint8Array>();
          state->args[r++] = (uint64_t)((uint8_t*)u8->Buffer()->Data() +
            u8->ByteOffset());
        }
        break;
      case FastTypes::u32array:
        {
          Local<Uint32Array> u32 = args[i].As<Uint32Array>();
          state->args[r++] = (uint64_t)((uint8_t*)u32->Buffer()->Data() +
            u32->ByteOffset());
        }
        break;
      case FastTypes::function:
        break;
      case FastTypes::f32:
        {
          float src = (float)args[i].As<v8::Number>()->Value();
          float* dst = (float*)&state->args[r++];
          *dst = src;
        }
        break;
      case FastTypes::f64:
        {
          //Local<Uint32Array> u32 = args[i].As<Uint32Array>();
          //state->args[r++] = (uint64_t)((uint8_t*)u32->Buffer()->Data() +
          //  u32->ByteOffset());
          double src = (double)args[i].As<v8::Number>()->Value();
          double* dst = (double*)&state->args[r++];
          *dst = src;
        }
        break;
    }
  }
  lo_fastcall(state);
  switch (state->result) {
    case FastTypes::i32:
      args.GetReturnValue().Set((int32_t)state->args[0]);
      break;
    case FastTypes::u32:
      args.GetReturnValue().Set((uint32_t)state->args[0]);
      break;
    case FastTypes::boolean:
      args.GetReturnValue().Set((bool)state->args[0]);
      break;
    case FastTypes::f32:
      {
        float* dst = (float*)&state->args[0];
        args.GetReturnValue().Set(Number::New(isolate, *dst));
      }
      break;
    case FastTypes::f64:
      {
        //double* res = (double*)args[args.Length() - 1]
        //  .As<Uint32Array>()->Buffer()->Data();
        //*res = state->args[0];
        double* dst = (double*)&state->args[0];
        args.GetReturnValue().Set(Number::New(isolate, *dst));
      }
      break;
    case FastTypes::i64:
      {
        int64_t* res = (int64_t*)args[args.Length() - 1]
          .As<Uint32Array>()->Buffer()->Data();
        *res = state->args[0];
      }
      break;
    case FastTypes::buffer:
    case FastTypes::u32array:
    case FastTypes::u64:
    case FastTypes::pointer:
      {
        uint64_t* res = (uint64_t*)args[args.Length() - 1]
          .As<Uint32Array>()->Buffer()->Data();
        *res = state->args[0];
      }
      break;
  }
}

void get_addressSlow(const FunctionCallbackInfo<Value> &args) {
  Local<TypedArray> ta = args[0].As<TypedArray>();
  uint8_t* ptr = (uint8_t*)ta->Buffer()->Data() + ta->ByteOffset();
  ((uint64_t*)args[1].As<Uint32Array>()->Buffer()->Data())[0] = (uint64_t)ptr;
}

void get_addressFast(void* p, struct FastApiArrayBufferView* const p_buf, 
  struct FastApiArrayBufferView* const p_ret) {
  ((uint64_t*)p_ret->data)[0] = (uint64_t)p_buf->data;
}

void get_callback_addressSlow(const FunctionCallbackInfo<Value> &args) {
  ((uint64_t*)args[0].As<Uint32Array>()->Buffer()->Data())[0] = (uint64_t)&lo_callback;
}

void bind_fastcallSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  // TODO - does integer work?
  struct fastcall* state = reinterpret_cast<struct fastcall*>(
    Local<Integer>::Cast(args[0])->Value());
  //Local<ObjectTemplate> tpl = ObjectTemplate::New(isolate);
  //tpl->SetInternalFieldCount(2);
  //Local<Object> data = tpl->NewInstance(context).ToLocalChecked();
  Local<Number> data = Number::New(isolate, (uint64_t)state);
  //data->SetAlignedPointerInInternalField(1, state);
  uint8_t unwrap = needsunwrap((FastTypes)state->result);
  int fastlen = state->nparam + 1 + unwrap;
  CTypeInfo* cargs = (CTypeInfo*)calloc(fastlen, sizeof(CTypeInfo));
  cargs[0] = CTypeInfo(CTypeInfo::Type::kV8Value);
  for (int i = 0; i < state->nparam; i++) {
    uint8_t ptype = state->param[i];
    cargs[i + 1] = *CTypeFromV8(ptype);
  }
  CTypeInfo* rc;
  if (unwrap) {
    cargs[fastlen - 1] = *CTypeFromV8(FastTypes::u32array);
    rc = CTypeFromV8(FastTypes::empty);
  } else {
    rc = CTypeFromV8((FastTypes)state->result);
  }
  CFunctionInfo* info = new CFunctionInfo(*rc, fastlen, cargs);
  CFunction* fastCFunc = new CFunction(state->wrapper, info);
  Local<FunctionTemplate> funcTemplate = FunctionTemplate::New(isolate,
    SlowCallback, data, Local<Signature>(), 0, ConstructorBehavior::kThrow,
    SideEffectType::kHasNoSideEffect, fastCFunc
  );
  Local<Function> fun =
    funcTemplate->GetFunction(context).ToLocalChecked();
  args.GetReturnValue().Set(fun);
}

void bind_slowcallSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  struct fastcall* state = reinterpret_cast<struct fastcall*>(
    Local<Integer>::Cast(args[0])->Value());
  //Local<ObjectTemplate> tpl = ObjectTemplate::New(isolate);
  //tpl->SetInternalFieldCount(2);
  Local<Number> data = Number::New(isolate, (uint64_t)state);
  //Local<Object> data = tpl->NewInstance(context).ToLocalChecked();
  //data->SetAlignedPointerInInternalField(1, state);
  Local<FunctionTemplate> funcTemplate = FunctionTemplate::New(isolate,
    SlowCallback, data, Local<Signature>(), 0, ConstructorBehavior::kThrow,
    SideEffectType::kHasNoSideEffect, 0
  );
  Local<Function> fun =
    funcTemplate->GetFunction(context).ToLocalChecked();
  args.GetReturnValue().Set(fun);
}

void wrap_memorySlow(const FunctionCallbackInfo<Value> &args) {
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
        start, size, [](void*, size_t, void*){}, nullptr);
    Local<ArrayBuffer> ab = ArrayBuffer::New(isolate, std::move(backing));
    args.GetReturnValue().Set(ab);
    return;
  }
  std::unique_ptr<BackingStore> backing = ArrayBuffer::NewBackingStore(
      start, size, FreeMemory, nullptr);
  Local<ArrayBuffer> ab = ArrayBuffer::New(isolate, std::move(backing));
  args.GetReturnValue().Set(ab);
}

void unwrap_memorySlow(const FunctionCallbackInfo<Value> &args) {
  Local<ArrayBuffer> ab = args[0].As<ArrayBuffer>();
  ab->Detach();
}

void utf8_lengthSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  args.GetReturnValue().Set(args[0].As<String>()->Utf8Length(isolate));
}

int32_t utf8_lengthFast (void* p, struct FastOneByteString* const p_str) {
  return p_str->length;
}

void register_callbackSlow(const FunctionCallbackInfo<Value>& args) {
  struct exec_info* info = reinterpret_cast<struct exec_info*>(
    (uint64_t)Local<Integer>::Cast(args[0])->Value());
  Local<Function> fn = args[1].As<Function>();
  int nargs = Local<Integer>::Cast(args[2])->Value();
  Isolate* isolate = args.GetIsolate();
  info->isolate = isolate;
  info->nargs = nargs;
  info->js_fn.Reset(isolate, Global<Function>(isolate, fn));
}



void dlopenSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  String::Utf8Value v0(isolate, args[0]);
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  void* rc = dlopen(*v0, v1);
  Local<ArrayBuffer> ab = args[2].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void dlopenFast(void* p, struct FastOneByteString* const p0, int32_t p1, struct FastApiArrayBufferView* const p_ret) {
  struct FastOneByteString* const v0 = p0;
  int32_t v1 = p1;
  void* r = dlopen(v0->data, v1);
  ((void**)p_ret->data)[0] = r;

}

void dlsymSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  void* rc = dlsym(v0, *v1);
  Local<ArrayBuffer> ab = args[2].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void dlsymFast(void* p, void* p0, struct FastOneByteString* const p1, struct FastApiArrayBufferView* const p_ret) {
  void* v0 = reinterpret_cast<void*>(p0);
  struct FastOneByteString* const v1 = p1;
  void* r = dlsym(v0, v1->data);
  ((void**)p_ret->data)[0] = r;

}

void aligned_allocSlow(const FunctionCallbackInfo<Value> &args) {
  uint32_t v0 = Local<Integer>::Cast(args[0])->Value();
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  void* rc = aligned_alloc(v0, v1);
  Local<ArrayBuffer> ab = args[2].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void aligned_allocFast(void* p, uint32_t p0, uint32_t p1, struct FastApiArrayBufferView* const p_ret) {
  uint32_t v0 = p0;
  uint32_t v1 = p1;
  void* r = aligned_alloc(v0, v1);
  ((void**)p_ret->data)[0] = r;

}

void mprotectSlow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t rc = mprotect(v0, v1, v2);
  args.GetReturnValue().Set(rc);
}

int32_t mprotectFast(void* p, void* p0, uint32_t p1, int32_t p2) {
  void* v0 = reinterpret_cast<void*>(p0);
  uint32_t v1 = p1;
  int32_t v2 = p2;
  return mprotect(v0, v1, v2);
}

void memcpySlow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  void* v1 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[1])->Value());
  uint32_t v2 = Local<Integer>::Cast(args[2])->Value();
  void* rc = memcpy(v0, v1, v2);
  Local<ArrayBuffer> ab = args[3].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void memcpyFast(void* p, void* p0, void* p1, uint32_t p2, struct FastApiArrayBufferView* const p_ret) {
  void* v0 = reinterpret_cast<void*>(p0);
  void* v1 = reinterpret_cast<void*>(p1);
  uint32_t v2 = p2;
  void* r = memcpy(v0, v1, v2);
  ((void**)p_ret->data)[0] = r;

}

void mmapSlow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t v3 = Local<Integer>::Cast(args[3])->Value();
  int32_t v4 = Local<Integer>::Cast(args[4])->Value();
  uint32_t v5 = Local<Integer>::Cast(args[5])->Value();
  void* rc = mmap(v0, v1, v2, v3, v4, v5);
  Local<ArrayBuffer> ab = args[6].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void mmapFast(void* p, void* p0, uint32_t p1, int32_t p2, int32_t p3, int32_t p4, uint32_t p5, struct FastApiArrayBufferView* const p_ret) {
  void* v0 = reinterpret_cast<void*>(p0);
  uint32_t v1 = p1;
  int32_t v2 = p2;
  int32_t v3 = p3;
  int32_t v4 = p4;
  uint32_t v5 = p5;
  void* r = mmap(v0, v1, v2, v3, v4, v5);
  ((void**)p_ret->data)[0] = r;

}

void munmapSlow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = munmap(v0, v1);
  args.GetReturnValue().Set(rc);
}

int32_t munmapFast(void* p, void* p0, uint32_t p1) {
  void* v0 = reinterpret_cast<void*>(p0);
  uint32_t v1 = p1;
  return munmap(v0, v1);
}

void memfd_createSlow(const FunctionCallbackInfo<Value> &args) {
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








void madviseSlow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  uint32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t rc = madvise(v0, v1, v2);
  args.GetReturnValue().Set(rc);
}

int32_t madviseFast(void* p, void* p0, uint32_t p1, int32_t p2) {
  void* v0 = reinterpret_cast<void*>(p0);
  uint32_t v1 = p1;
  int32_t v2 = p2;
  return madvise(v0, v1, v2);
}

void sleepSlow(const FunctionCallbackInfo<Value> &args) {
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  sleep(v0);
}

void sleepFast(void* p, int32_t p0) {
  int32_t v0 = p0;
  sleep(v0);
}

void usleepSlow(const FunctionCallbackInfo<Value> &args) {
  uint32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t rc = usleep(v0);
  args.GetReturnValue().Set(rc);
}

int32_t usleepFast(void* p, uint32_t p0) {
  uint32_t v0 = p0;
  return usleep(v0);
}


void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "dlopen", &pFdlopen, dlopenSlow);
NODE_SET_FAST_METHOD(isolate, exports, "dlsym", &pFdlsym, dlsymSlow);
NODE_SET_FAST_METHOD(isolate, exports, "aligned_alloc", &pFaligned_alloc, aligned_allocSlow);
NODE_SET_FAST_METHOD(isolate, exports, "mprotect", &pFmprotect, mprotectSlow);
NODE_SET_FAST_METHOD(isolate, exports, "memcpy", &pFmemcpy, memcpySlow);
NODE_SET_FAST_METHOD(isolate, exports, "mmap", &pFmmap, mmapSlow);
NODE_SET_FAST_METHOD(isolate, exports, "munmap", &pFmunmap, munmapSlow);
NODE_SET_FAST_METHOD(isolate, exports, "memfd_create", &pFmemfd_create, memfd_createSlow);
NODE_SET_METHOD(exports, "bind_fastcall", bind_fastcallSlow);
NODE_SET_METHOD(exports, "bind_slowcall", bind_slowcallSlow);
NODE_SET_METHOD(exports, "register_callback", register_callbackSlow);
NODE_SET_FAST_METHOD(isolate, exports, "get_address", &pFget_address, get_addressSlow);
NODE_SET_METHOD(exports, "get_callback_address", get_callback_addressSlow);
NODE_SET_METHOD(exports, "wrap_memory", wrap_memorySlow);
NODE_SET_METHOD(exports, "unwrap_memory", unwrap_memorySlow);
NODE_SET_FAST_METHOD(isolate, exports, "madvise", &pFmadvise, madviseSlow);
NODE_SET_FAST_METHOD(isolate, exports, "sleep", &pFsleep, sleepSlow);
NODE_SET_FAST_METHOD(isolate, exports, "usleep", &pFusleep, usleepSlow);
NODE_SET_FAST_METHOD(isolate, exports, "utf8_length", &pFutf8_length, utf8_lengthSlow);
    NODE_SET_VALUE(isolate, exports, "PROT_READ", Integer::New(isolate, (int32_t)PROT_READ));
  NODE_SET_VALUE(isolate, exports, "MAP_PRIVATE", Integer::New(isolate, (int32_t)MAP_PRIVATE));
  NODE_SET_VALUE(isolate, exports, "PROT_WRITE", Integer::New(isolate, (int32_t)PROT_WRITE));
  NODE_SET_VALUE(isolate, exports, "PROT_EXEC", Integer::New(isolate, (int32_t)PROT_EXEC));
  NODE_SET_VALUE(isolate, exports, "MAP_ANONYMOUS", Integer::New(isolate, (int32_t)MAP_ANONYMOUS));
  NODE_SET_VALUE(isolate, exports, "struct_fastcall_size", Integer::New(isolate, (uint32_t)struct_fastcall_size));
  NODE_SET_VALUE(isolate, exports, "RTLD_LAZY", Integer::New(isolate, (int32_t)RTLD_LAZY));
  NODE_SET_VALUE(isolate, exports, "RTLD_LOCAL", Integer::New(isolate, (int32_t)RTLD_LOCAL));
  NODE_SET_VALUE(isolate, exports, "RTLD_NOLOAD", Integer::New(isolate, (int32_t)RTLD_NOLOAD));
  NODE_SET_VALUE(isolate, exports, "RTLD_NOW", Integer::New(isolate, (int32_t)RTLD_NOW));
  NODE_SET_VALUE(isolate, exports, "RTLD_GLOBAL", Integer::New(isolate, (int32_t)RTLD_GLOBAL));
  NODE_SET_VALUE(isolate, exports, "RTLD_DEFAULT", BigInt::New(isolate, (uint64_t)RTLD_DEFAULT));
  NODE_SET_VALUE(isolate, exports, "RTLD_NEXT", BigInt::New(isolate, (uint64_t)RTLD_NEXT));
  NODE_SET_VALUE(isolate, exports, "MADV_HUGEPAGE", Integer::New(isolate, (int32_t)MADV_HUGEPAGE));

}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
