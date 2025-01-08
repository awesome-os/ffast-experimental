import { createRequire } from "node:module"
import { assert, wrap, utf8_decode, strnlen } from './ffast.js'

const seccomp = createRequire(import.meta.url)('../build/Release/seccomp.node')

const SYSCALL_NAME_MAX_LEN = 128
const u32 = new Uint32Array(2)
const seccomp_init = wrap(u32, seccomp.seccomp_init, 1)
const seccomp_syscall_resolve_num_arch = 
  wrap(u32, seccomp.seccomp_syscall_resolve_num_arch, 2)
const {
  seccomp_rule_add_exact, seccomp_load, seccomp_release, 
  seccomp_syscall_resolve_name,
/**
 * Kill the process
 */
  SCMP_ACT_KILL_PROCESS,
/**
 * Kill the thread
 */
  SCMP_ACT_KILL_THREAD,
/**
 * Kill the thread, defined for backward compatibility
 */
  SCMP_ACT_KILL,
/**
 * Throw a SIGSYS signal
 */
  SCMP_ACT_TRAP,
/**
 * Notifies userspace
 */
  SCMP_ACT_NOTIFY,
/**
 * Allow the syscall to be executed after the action has been logged
 */
  SCMP_ACT_LOG,
/**
 * Allow the syscall to be executed
 */
  SCMP_ACT_ALLOW,
  SCMP_ARCH_X86_64
} = seccomp

/**
 * Return the specified error code
 */
const SCMP_ACT_ERRNO = (x) => (0x00050000 | ((x) & 0x0000ffff))

/**
 * Notify a tracing process with the specified value
 */
const SCMP_ACT_TRACE = (x) => (0x7ff00000 | ((x) & 0x0000ffff))

class Context {
  ctx = 0

  static get_name (syscall_nr = 0) {
    const ptr = assert(seccomp_syscall_resolve_num_arch(SCMP_ARCH_X86_64, 
      syscall_nr))
    return utf8_decode(ptr, strnlen(ptr, SYSCALL_NAME_MAX_LEN))
  }

  static get_number (syscall_name = '') {
    return seccomp_syscall_resolve_name(syscall_name)
  }

  init (defaultAction = SCMP_ACT_KILL_PROCESS) {
    const ctx = seccomp_init(defaultAction)
    assert(ctx)
    this.ctx = ctx
  }

  add_rule (syscall_nr, action = SCMP_ACT_ALLOW) {
    assert(seccomp_rule_add_exact(this.ctx, action, syscall_nr, 0) === 0)
  }

  load () {
    assert(seccomp_load(this.ctx) === 0)
  }

  release () {
    seccomp_release(this.ctx)
  }
}

export { 
  Context,
  SCMP_ACT_KILL_PROCESS,
  SCMP_ACT_KILL_THREAD,
  SCMP_ACT_KILL,
  SCMP_ACT_TRAP,
  SCMP_ACT_NOTIFY,
  SCMP_ACT_LOG,
  SCMP_ACT_ALLOW,
  SCMP_ARCH_X86_64,
  SCMP_ACT_ERRNO,
  SCMP_ACT_TRACE,
}
