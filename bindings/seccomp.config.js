const api = {
  seccomp_syscall_resolve_num_arch: {
    parameters: ['i32', 'i32'],
    result: 'pointer',
    rpointer: 'const char*'
  },
  seccomp_init: {
    parameters: ['u32'],
    result: 'pointer',
    rpointer: 'scmp_filter_ctx'
  },
  seccomp_rule_add_exact: {
    parameters: ['pointer', 'u32', 'i32', 'u32'],
    pointers: ['scmp_filter_ctx'],
    result: 'i32'
  },
  seccomp_load: {
    parameters: ['pointer'],
    pointers: ['scmp_filter_ctx'],
    result: 'i32'
  },
  seccomp_release: {
    parameters: ['pointer'],
    pointers: ['scmp_filter_ctx'],
    result: 'void'
  },
  seccomp_syscall_resolve_name: {
    parameters: ['string'],
    pointers: ['const char*'],
    result: 'i32'
  }
}

const name = 'seccomp'
const includes = ['<seccomp.h>']
const libs = ['seccomp']

const preamble = `
using v8::Uint32Array;
`

const constants = {
  SCMP_ACT_KILL_PROCESS: 'i32',
  SCMP_ACT_KILL_THREAD: 'i32',
  SCMP_ACT_KILL: 'i32',
  SCMP_ACT_TRAP: 'i32',
  SCMP_ACT_NOTIFY: 'i32',
  SCMP_ACT_LOG: 'i32',
  SCMP_ACT_ALLOW: 'i32',
  SCMP_ARCH_X86_64: 'i32'
}

export { api, name, includes, libs, preamble, constants }
