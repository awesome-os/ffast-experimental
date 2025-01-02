import { createRequire } from "node:module"
import { Compiler } from './lib/tcc.js'
import { assert } from './lib/ffast.js'
import { Bench } from './lib/bench.js'

const noop = createRequire(import.meta.url)('./build/Release/noop.node')

const compiler = new Compiler()

compiler.compile(`
void noop () {
}
`)

const { noop_fast, noop_slow } = noop

const bench = new Bench()

while (1) {
  for (let j = 0; j < 5; j++) {
    const runs = 300000000
    bench.start('noop_fast')
    for (let i = 0; i < runs; i++) assert(noop_fast() === undefined)
    bench.end(runs)
  }

  for (let j = 0; j < 5; j++) {
    const runs = 100000000
    bench.start('noop_slow')
    for (let i = 0; i < runs; i++) assert(noop_slow() === undefined)
    bench.end(runs)
  }
}
