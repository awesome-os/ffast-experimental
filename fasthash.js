import { 
  assert, ptr, dlopen, dlsym, RTLD_LAZY, RTLD_LOCAL, RTLD_DEFAULT, compiler, asm, Registers,
  bind, bind_custom, RTLD_NOLOAD, RTLD_GLOBAL, RTLD_NOW
} from './lib/ffast.js'
import { Bench } from './lib/bench.js'

const LAZY_LOCAL = RTLD_LAZY | RTLD_LOCAL

const handle = assert(dlopen('../lo/lib/boringssl/deps/boringssl/build/libcrypto.so', LAZY_LOCAL))
//const handle = assert(dlopen('libcrypto.so', RTLD_LAZY | RTLD_GLOBAL))
//const handle = assert(dlopen('libcrypto.so', RTLD_NOW | RTLD_LOCAL))
//const handle = 0
/*
boringssl = 156 ns
node openssl = 476 ns
bun = 400 ns
*/
const sizes = {
  md5: 16, sha1: 20, sha256: 32, sha384: 48, sha512: 64
}

const EVP_MD_CTX_new_sym = assert(dlsym(handle, 'EVP_MD_CTX_new'))
const EVP_DigestInit_ex_sym = assert(dlsym(handle, 'EVP_DigestInit_ex'))
const EVP_DigestUpdate_sym = assert(dlsym(handle, 'EVP_DigestUpdate'))
const EVP_DigestFinal_ex_sym = assert(dlsym(handle, 'EVP_DigestFinal_ex'))
const EVP_MD_CTX_reset_sym = assert(dlsym(handle, 'EVP_MD_CTX_reset'))
const EVP_sha1_sym = assert(dlsym(handle, 'EVP_sha1'))
const EVP_md5_sym = assert(dlsym(handle, 'EVP_md5'))
const EVP_sha256_sym = assert(dlsym(handle, 'EVP_sha256'))

const EVP_MD_CTX_new = bind(EVP_MD_CTX_new_sym, 'pointer', [])
const EVP_DigestInit_ex = bind(EVP_DigestInit_ex_sym, 'i32', ['pointer', 'pointer', 'pointer'])
const EVP_DigestUpdate = bind(EVP_DigestUpdate_sym, 'i32', ['pointer', 'pointer', 'u32'])
const EVP_DigestFinal_ex = bind(EVP_DigestFinal_ex_sym, 'i32', ['pointer', 'pointer', 'pointer'])
const EVP_sha1 = bind(EVP_sha1_sym, 'pointer', [])
const EVP_md5 = bind(EVP_md5_sym, 'pointer', [])
const EVP_sha256 = bind(EVP_sha256_sym, 'pointer', [])

const hash_type = EVP_md5()
const hash_context = assert(EVP_MD_CTX_new())
const hash_hsize = ptr(new Uint32Array(2))
const hash_digest = ptr(new Uint8Array(sizes.md5))

const encoder = new TextEncoder()
const u8 = ptr(encoder.encode('hello'))

const u8_ptr = u8.ptr
const u8_length = u8.length
const digest_ptr = hash_digest.ptr
const hsize_ptr = hash_hsize.ptr

const { rdi, rsi, rdx, rbx, rax } = Registers

asm.reset()
asm.push(rsi)
asm.push(rdx)
asm.movabs(hash_context, rdi)
asm.movabs(hash_type, rsi)
asm.movabs(0, rdx)
asm.push(rdi)
asm.call(EVP_DigestInit_ex_sym)
asm.pop(rdi)
asm.pop(rdx)
asm.pop(rsi)
asm.push(rdi)
asm.call(EVP_DigestUpdate_sym)
asm.pop(rdi)
asm.movabs(digest_ptr, rsi)
asm.movabs(hsize_ptr, rdx)
asm.jmp(EVP_DigestFinal_ex_sym)

const fast_addr = compiler.compile(asm.bytes())

asm.reset()
asm.push(rbx)
asm.movreg(rdi, rbx)
asm.movabs(hash_context, rdi)
asm.movabs(hash_type, rsi)
//asm.zero(rdx)
asm.movabs(0, rdx)
asm.push(rdi)
asm.call(EVP_DigestInit_ex_sym)
asm.pop(rdi)
asm.movsrc(rbx, rsi, 8)
asm.movsrc(rbx, rdx, 16)
asm.push(rdi)
asm.call(EVP_DigestUpdate_sym)
asm.pop(rdi)
asm.movabs(digest_ptr, rsi)
asm.movabs(hsize_ptr, rdx)
asm.call(EVP_DigestFinal_ex_sym)
asm.movdest(rax, rbx, 0)
asm.pop(rbx)
asm.ret()

const slow_addr = compiler.compile(asm.bytes())
const hash_fast = bind_custom('i32', ['pointer', 'u32'], slow_addr, fast_addr)

function hash (src, src_len) {
  assert(hash_fast(src, src_len) === 1)
  assert(hash_hsize[0] === 16)
  return hash_digest
}

function hash_normal (src, src_len, digest, sz) {
  assert(EVP_DigestInit_ex(hash_context, hash_type, 0) === 1)
  assert(EVP_DigestUpdate(hash_context, src, src_len) === 1)
  assert(EVP_DigestFinal_ex(hash_context, digest, sz) === 1)
  assert(hash_hsize[0] === 16)
  return hash_digest
}

const iter = parseInt(args[0] || '5', 10)
const runs = parseInt(args[1] || '10000000', 10)
const bench = new Bench()

const expected = [ 
  93, 65, 64, 42, 188, 75, 42, 118, 185, 113, 157, 145, 16, 23, 197, 146 
]

hash_normal(u8_ptr, u8_length, digest_ptr, hsize_ptr)
hash_digest.forEach((v, i) => assert(v === expected[i]))

hash(u8_ptr, u8_length)
//hash_digest.forEach((v, i) => assert(v === expected[i]))

console.log('foo')
{

  for (let i = 0; i < iter; i++) {
    bench.start('md5-fast')
    for (let j = 0; j < runs; j++) {
      hash(u8_ptr, u8_length)
    }
    bench.end(runs, u8_length)
  }

  for (let i = 0; i < iter; i++) {
    bench.start('md5-full')
    for (let j = 0; j < runs; j++) {
      hash_normal(u8_ptr, u8_length, digest_ptr, hsize_ptr)
    }
    bench.end(runs, u8_length)
  }
}