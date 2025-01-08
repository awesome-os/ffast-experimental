import { Bench } from './lib/bench.js'
import { 
  assert, utf8_length, asm, compiler, bind_custom, dlsym, Registers, dlopen, 
  bindall, RTLD_NOW, RTLD_LOCAL, addr
} from './lib/ffast.js'
import { api } from './bindings/sqlite.config.js'

//const sqlite_handle = assert(dlopen('./build/Release/sqlite.node', RTLD_NOW | RTLD_LOCAL))
const sqlite_handle = assert(dlopen('../lo/lib/sqlite/deps/sqlite/.libs/libsqlite3.so', RTLD_NOW | RTLD_LOCAL))
const sqlite = bindall(api, sqlite_handle)
const { open2, exec, close2, prepare2 } = sqlite
const { compile } = compiler

const OK = 0
const ROW = 100
const OPEN_CREATE = 0x00000004
const OPEN_READWRITE = 0x00000002
const OPEN_NOMUTEX = 0x00008000
const { rdi, rsi, rbx, rax} = Registers

const handle = new Uint32Array(2)
assert(open2(':memory:', handle, OPEN_CREATE | OPEN_READWRITE | OPEN_NOMUTEX, 0) === OK)
const db = assert(addr(handle))

assert(exec(db, 'pragma user_version = 100', 0, 0, handle) === OK)

const column_int_addr = assert(dlsym(sqlite_handle, 'sqlite3_column_int'))
const step_addr = assert(dlsym(sqlite_handle, 'sqlite3_step'))
const reset_addr = assert(dlsym(sqlite_handle, 'sqlite3_reset'))
const finalize_addr = assert(dlsym(sqlite_handle, 'sqlite3_finalize'))

const sql = 'pragma user_version'

assert(prepare2(db, sql, utf8_length(sql), handle, 0) === OK)
const stmt = assert(addr(handle))

const column_int = bind_custom('i32', ['u32'], compile(asm
  .reset()
  .push(rbx)
  .movreg(rdi, rbx)
  .movabs(stmt, rdi)
  .movsrc(rbx, rsi, 8)
  .call(column_int_addr)
  .movdest(rax, rbx, 0)
  .pop(rbx)
  .ret()
  .bytes()
), compile(asm
  .reset()
  .movreg(rsi, rdi)
  .movabs(stmt, rdi)
  .jmp(column_int_addr)
  .bytes()
))
const step = bind_custom('i32', [], compile(asm
  .reset()
  .push(rbx)
  .movreg(rdi, rbx)
  .movabs(stmt, rdi)
  .call(step_addr)
  .movdest(rax, rbx, 0)
  .pop(rbx)
  .ret()
  .bytes()
), compile(asm
  .reset()
  .movabs(stmt, rdi)
  .jmp(step_addr)
  .bytes()
))
const reset = bind_custom('i32', [], compile(asm
  .reset()
  .push(rbx)
  .movreg(rdi, rbx)
  .movabs(stmt, rdi)
  .call(reset_addr)
  .movdest(rax, rbx, 0)
  .pop(rbx)
  .ret()
  .bytes()
), compile(asm
  .reset()
  .movabs(stmt, rdi)
  .jmp(reset_addr)
  .bytes()
))
const finalize = bind_custom('i32', [], compile(asm
  .reset()
  .push(rbx)
  .movreg(rdi, rbx)
  .movabs(stmt, rdi)
  .call(finalize_addr)
  .movdest(rax, rbx, 0)
  .pop(rbx)
  .ret()
  .bytes()
), compile(asm
  .reset()
  .movabs(stmt, rdi)
  .jmp(finalize_addr)
  .bytes()
))

// if we added some comparison ops and ability to label code and do conditionak
// jumps then we could translate this whole function into a single function with
// assembly alone
function get_version () {
  reset()
  if(step() === ROW) return column_int(0)
  finalize()
  return 0
}

assert(get_version() === 100)

const runs = 10000000
const iter = 10
const bench = new Bench()

for (let i = 0; i < iter; i++) {
  bench.start('pragma user_version')
  for (let j = 0; j < runs; j++) {
    assert(get_version() === 100)
  }
  bench.end(runs)
}

finalize()
close2(db)
