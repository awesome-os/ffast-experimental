import { assert, mmap, mprotect, PROT_WRITE, MAP_ANONYMOUS, MAP_PRIVATE, PROT_EXEC, PROT_READ } from './lib/ffast.js'
import * as seccomp from './lib/seccomp.js'

const { Context } = seccomp
const { get_name, get_number } = Context

const ctx = new Context()
ctx.init(seccomp.SCMP_ACT_LOG)

let syscall_nr = 0

while (1) {
  try {
    const name = get_name(syscall_nr)
    assert(syscall_nr === get_number(name))
    if (name === 'mprotect') {
      console.log(`${syscall_nr} : ${name}`)
      ctx.add_rule(syscall_nr, seccomp.SCMP_ACT_KILL_PROCESS)
    }
    syscall_nr += 1
  } catch (err) {
//console.log(err.stack)
    break
  }
}

ctx.load()

const address = mmap(0, 1024, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 
  -1, new Uint32Array(2))
assert(address)
assert(mprotect(address, 1024, PROT_EXEC | PROT_READ) === 0)

ctx.release()

