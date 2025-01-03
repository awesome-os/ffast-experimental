
#include "ffast.h"

namespace ffast {

uint32_t memcount_sseFast(void* p, void* p0, int32_t p1, uint32_t p2);
v8::CTypeInfo cargsmemcount_sse[4] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
};
v8::CTypeInfo rcmemcount_sse = v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
v8::CFunctionInfo infomemcount_sse = v8::CFunctionInfo(rcmemcount_sse, 4, cargsmemcount_sse);
v8::CFunction pFmemcount_sse = v8::CFunction((const void*)&memcount_sseFast, &infomemcount_sse);


uint32_t memcount_avx2Fast(void* p, void* p0, int32_t p1, uint32_t p2);
v8::CTypeInfo cargsmemcount_avx2[4] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32),
};
v8::CTypeInfo rcmemcount_avx2 = v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
v8::CFunctionInfo infomemcount_avx2 = v8::CFunctionInfo(rcmemcount_avx2, 4, cargsmemcount_avx2);
v8::CFunction pFmemcount_avx2 = v8::CFunction((const void*)&memcount_avx2Fast, &infomemcount_avx2);


#include <immintrin.h>

size_t memcount_sse(const void *s, int c, size_t n) {    
    __m128i cv = _mm_set1_epi8(c), sum = _mm_setzero_si128(), acr0,acr1,acr2,acr3;
    const char *p,*pe;						    											   
  const char* ss = (const char*)s;		    											   
	for(p = ss; p != ss+(n- (n % (252*16)));) { 
	  for(acr0 = acr1 = acr2 = acr3 = _mm_setzero_si128(),pe = p+252*16; p != pe; p += 64) { 
		acr0 = _mm_add_epi8(acr0, _mm_cmpeq_epi8(cv, _mm_loadu_si128((const __m128i *)p))); 
		acr1 = _mm_add_epi8(acr1, _mm_cmpeq_epi8(cv, _mm_loadu_si128((const __m128i *)(p+16)))); 
		acr2 = _mm_add_epi8(acr2, _mm_cmpeq_epi8(cv, _mm_loadu_si128((const __m128i *)(p+32)))); 
		acr3 = _mm_add_epi8(acr3, _mm_cmpeq_epi8(cv, _mm_loadu_si128((const __m128i *)(p+48)))); __builtin_prefetch(p+1024);
	  }
      sum = _mm_add_epi64(sum, _mm_sad_epu8(_mm_sub_epi8(_mm_setzero_si128(), acr0), _mm_setzero_si128()));
      sum = _mm_add_epi64(sum, _mm_sad_epu8(_mm_sub_epi8(_mm_setzero_si128(), acr1), _mm_setzero_si128()));
      sum = _mm_add_epi64(sum, _mm_sad_epu8(_mm_sub_epi8(_mm_setzero_si128(), acr2), _mm_setzero_si128()));
      sum = _mm_add_epi64(sum, _mm_sad_epu8(_mm_sub_epi8(_mm_setzero_si128(), acr3), _mm_setzero_si128()));
    }
    size_t count = _mm_extract_epi64(sum, 0) + _mm_extract_epi64(sum, 1);   
    while(p != ss + n) count += *p++ == c;
    return count;
}

size_t memcount_avx2(const void *s, int c, size_t n) {    
    __m256i cv = _mm256_set1_epi8(c), zv = _mm256_setzero_si256(), sum = zv, acr0,acr1,acr2,acr3;
    const char *p,*pe;
  const char* ss = (const char*)s;		    											   
	for(p = ss; p != ss+(n- (n % (252*32)));) { 
	  for(acr0 = acr1 = acr2 = acr3 = zv,pe = p+252*32; p != pe; p += 128) { 
		acr0 = _mm256_add_epi8(acr0, _mm256_cmpeq_epi8(cv, _mm256_lddqu_si256((const __m256i *)p))); 
		acr1 = _mm256_add_epi8(acr1, _mm256_cmpeq_epi8(cv, _mm256_lddqu_si256((const __m256i *)(p+32)))); 
		acr2 = _mm256_add_epi8(acr2, _mm256_cmpeq_epi8(cv, _mm256_lddqu_si256((const __m256i *)(p+64)))); 
		acr3 = _mm256_add_epi8(acr3, _mm256_cmpeq_epi8(cv, _mm256_lddqu_si256((const __m256i *)(p+96)))); __builtin_prefetch(p+1024);
	  }
      sum = _mm256_add_epi64(sum, _mm256_sad_epu8(_mm256_sub_epi8(zv, acr0), zv));
      sum = _mm256_add_epi64(sum, _mm256_sad_epu8(_mm256_sub_epi8(zv, acr1), zv));
      sum = _mm256_add_epi64(sum, _mm256_sad_epu8(_mm256_sub_epi8(zv, acr2), zv));
      sum = _mm256_add_epi64(sum, _mm256_sad_epu8(_mm256_sub_epi8(zv, acr3), zv));
    }	
    for(acr0=zv; p+32 < ss + n; p += 32)  
      acr0 = _mm256_add_epi8(acr0, _mm256_cmpeq_epi8(cv, _mm256_lddqu_si256((const __m256i *)p))); 
    sum = _mm256_add_epi64(sum, _mm256_sad_epu8(_mm256_sub_epi8(zv, acr0), zv));
    size_t count = _mm256_extract_epi64(sum, 0) + _mm256_extract_epi64(sum, 1) + _mm256_extract_epi64(sum, 2) + _mm256_extract_epi64(sum, 3);   
    while(p != ss + n) count += *p++ == c;
    return count;
}



void memcount_sseSlow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  uint32_t v2 = Local<Integer>::Cast(args[2])->Value();
  uint32_t rc = memcount_sse(v0, v1, v2);
  args.GetReturnValue().Set(rc);
}

uint32_t memcount_sseFast(void* p, void* p0, int32_t p1, uint32_t p2) {
  void* v0 = reinterpret_cast<void*>(p0);
  int32_t v1 = p1;
  uint32_t v2 = p2;
  return memcount_sse(v0, v1, v2);
}

void memcount_avx2Slow(const FunctionCallbackInfo<Value> &args) {
  void* v0 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  uint32_t v2 = Local<Integer>::Cast(args[2])->Value();
  uint32_t rc = memcount_avx2(v0, v1, v2);
  args.GetReturnValue().Set(rc);
}

uint32_t memcount_avx2Fast(void* p, void* p0, int32_t p1, uint32_t p2) {
  void* v0 = reinterpret_cast<void*>(p0);
  int32_t v1 = p1;
  uint32_t v2 = p2;
  return memcount_avx2(v0, v1, v2);
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "memcount_sse", &pFmemcount_sse, memcount_sseSlow);
NODE_SET_FAST_METHOD(isolate, exports, "memcount_avx2", &pFmemcount_avx2, memcount_avx2Slow);
  
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
