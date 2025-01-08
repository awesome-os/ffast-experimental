import { Database } from "jsr:@db/sqlite@0.12"
import { Bench } from './lib/bench.js'

const db = new Database(':memory:', { unsafeConcurrency: true })
db.exec('pragma user_version = 100')
const stmt = db.prepare('pragma user_version')

assert(stmt.get().user_version === 100)

const runs = 10000000
const iter = 10
const bench = new Bench()

for (let i = 0; i < iter; i++) {
  bench.start('pragma user_version')
  for (let j = 0; j < runs; j++) {
    assert(stmt.get().user_version === 100)
  }
  bench.end(runs)
}

db.close()
