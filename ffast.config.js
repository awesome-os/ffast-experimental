const api = {
  dlsym: {
    parameters: ['pointer', 'string'],
    pointers: ['void*', 'const char*'],
    result: 'pointer',
  },
  mprotect: {
    parameters: ['pointer', 'u32', 'i32'],
    result: 'i32',
  },
  memcpy: {
    parameters: ['pointer', 'pointer', 'u32'],
    result: 'pointer',
  },
  mmap: {
    parameters: ['pointer', 'u32', 'i32', 'i32', 'i32', 'u32'],
    result: 'pointer',
  },
  munmap: {
    parameters: ['pointer', 'u32'],
    result: 'i32',
  },
  memfd_create: {
    parameters: ['string', 'u32'],
    result: 'i32',
  },
}

const constants = {
  PROT_READ: 'i32', 
  MAP_PRIVATE: 'i32', 
  PROT_WRITE: 'i32', 
  PROT_EXEC: 'i32', 
  MAP_ANONYMOUS: 'i32',
}

const name = 'ffast'

export { api, name, constants }
