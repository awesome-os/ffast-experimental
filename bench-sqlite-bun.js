import { Database } from 'bun:sqlite'
import { Bench } from './lib/bench.js'

const db = Database.open(':memory:')
db.exec('pragma user_version = 100')
db.exec('drop table if exists foo')
db.exec('create table if not exists foo (num int)')
db.exec('insert into foo (num) values (1)')

const user_version = db.prepare('pragma user_version')
const select_number = db.prepare('select num from foo limit 1')

assert(user_version.get().user_version === 100)
assert(select_number.get().num === 1)

const runs = 10000000
const iter = 5
const bench = new Bench()

for (let i = 0; i < iter; i++) {
  bench.start('user_version')
  for (let j = 0; j < runs; j++) {
    assert(user_version.get().user_version === 100)
  }
  bench.end(runs)
}

for (let i = 0; i < iter; i++) {
  bench.start('select_number')
  for (let j = 0; j < runs; j++) {
    assert(select_number.get().num === 1)
  }
  bench.end(runs)
}

db.close()
