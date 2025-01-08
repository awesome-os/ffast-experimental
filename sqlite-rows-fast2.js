import { Bench } from './lib/bench.js'
import { 
  assert, utf8_length, asm, compiler, bind_custom, dlsym, Registers, dlopen, 
  bindall, RTLD_NOW, RTLD_LOCAL, addr, ptr
} from './lib/ffast.js'
import { api } from './bindings/sqlite.config.js'

function bind_statement (sql) {
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
  const five_columns = bind_custom('void', ['pointer'], compile(asm
    .reset()
    .push(rbx)
    .movreg(rdi, rbx)
    .movsrc(rbx, rdx, 8)

    .movabs(stmt, rdi)
    .movabs(0, rsi)
    .call(column_int_addr)

    .movdest(rax, rbx, 0)
/*
    .movabs(stmt, rdi)
    .movabs(1, rsi)
    .call(column_int_addr)
    .movdest(rax, rbx, 8)

    .movabs(stmt, rdi)
    .movabs(2, rsi)
    .call(column_int_addr)
    .movdest(rax, rbx, 16)

    .movabs(stmt, rdi)
    .movabs(3, rsi)
    .call(column_int_addr)
    .movdest(rax, rbx, 24)

    .movabs(stmt, rdi)
    .movabs(4, rsi)
    .call(column_int_addr)
    .movdest(rax, rbx, 32)
*/
    .pop(rbx)
    .ret()
    .bytes()
  ), compile(asm
    .reset()
    .movabs(0, rsi)
    .movabs(stmt, rdi)
    .jmp(column_int_addr)
    .bytes()
  ))
  return { reset, step, column_int, finalize, five_columns }
}

function execute_sql (sql) {
  assert(exec(db, sql, 0, 0, handle) === OK)
}

function bind_library () {
  const sqlite_handle = assert(dlopen(library_path, RTLD_NOW | RTLD_LOCAL))
  const sqlite = bindall(api, sqlite_handle)
  sqlite.column_int_addr = assert(dlsym(sqlite_handle, 'sqlite3_column_int'))
  sqlite.step_addr = assert(dlsym(sqlite_handle, 'sqlite3_step'))
  sqlite.reset_addr = assert(dlsym(sqlite_handle, 'sqlite3_reset'))
  sqlite.finalize_addr = assert(dlsym(sqlite_handle, 'sqlite3_finalize'))
  return sqlite
}

function open_database (path) {
  assert(open2(path, handle, flags, 0) === OK)
  return assert(addr(handle))
}

function get_version () {
  const { reset, step, column_int } = user_version
  assert(reset() === OK)
  if(step() === ROW) return column_int(0)
  return 0
}

function get_lots_of_numbers () {
  const { reset, step, column_int } = lots_of_numbers
  assert(reset() === OK)
  const rows = []
  while (step() === ROW) {
    rows.push([column_int(0), column_int(1), column_int(2), column_int(3), column_int(4)])
  }
  return rows
}

const OK = 0
const ROW = 100
const OPEN_CREATE = 0x00000004
const OPEN_READWRITE = 0x00000002
const OPEN_NOMUTEX = 0x00008000
const { rdi, rsi, rbx, rax, rdx} = Registers
const handle = new Uint32Array(2)
const { compile } = compiler
const library_path = '../lo/lib/sqlite/deps/sqlite/.libs/libsqlite3.so'
const flags = OPEN_CREATE | OPEN_READWRITE | OPEN_NOMUTEX

const { 
  open2, exec, close2, prepare2,
  column_int_addr, step_addr, reset_addr, finalize_addr
} = bind_library()
const db = open_database(':memory:')

execute_sql('create table if not exists lots_of_numbers (num1 int, num2 int, num3 int, num4 int, num5 int)')
execute_sql('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (1, 2, 3, 4, 5)')
execute_sql('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (10, 20, 30, 40, 50)')
execute_sql('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (100, 200, 300, 400, 500)')
execute_sql('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (1000, 2000, 3000, 4000, 5000)')
execute_sql('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (10000, 20000, 30000, 40000, 50000)')

const user_version = bind_statement('pragma user_version')
const lots_of_numbers = bind_statement('select num1, num2, num3, num4, num5 from lots_of_numbers limit 5')

lots_of_numbers.reset()
lots_of_numbers.step()
const buf = ptr(new Uint8Array(40))
console.log(lots_of_numbers.five_columns(buf.ptr))
console.log(Array.from(buf))

assert(get_version() === 0)
assert(get_lots_of_numbers().length === 5)

const iter = 10
const bench = new Bench()
{
  const runs = 1200000

  for (let i = 0; i < iter; i++) {
    bench.start('get_lots_of_numbers')
    for (let j = 0; j < runs; j++) {
      assert(get_lots_of_numbers().length === 5)
    }
    bench.end(runs)
  }
}

lots_of_numbers.finalize()

close2(db)
