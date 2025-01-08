import { Database } from './lib/sqlite.js'
import { Bench } from './lib/bench.js'

const db = new Database().open(':memory:')
db.exec('create table if not exists lots_of_numbers (num1 int, num2 int, num3 int, num4 int, num5 int)')
db.exec('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (1, 2, 3, 4, 5)')
db.exec('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (10, 20, 30, 40, 50)')
db.exec('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (100, 200, 300, 400, 500)')
db.exec('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (1000, 2000, 3000, 4000, 5000)')
db.exec('insert into lots_of_numbers (num1, num2, num3, num4, num5) values (10000, 20000, 30000, 40000, 50000)')

const stmt = db.prepare('select num1, num2, num3, num4, num5 from lots_of_numbers limit 5').compile('lots_of_numbers', true)

const runs = 1000000
const iter = 10
const bench = new Bench()

for (let i = 0; i < iter; i++) {
  bench.start('lots_of_numbers')
  for (let j = 0; j < runs; j++) {
    assert(stmt.all().length === 5)
  }
  bench.end(runs)
}

stmt.finalize()
db.close()
