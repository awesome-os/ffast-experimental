import { C } from './lib/C.js'
import { Bench } from './lib/bench.js'
import { assert } from './lib/ffast.js'

const { test } = C`
${{ test: { result: 'i32', parameters: [] } }}

#include <stdlib.h>

int test() {
  return 42;
}
`
const bench = new Bench()
const runs = 500000000

while (1) {
  bench.start('c-test')
  for (let i = 0; i < runs; i++) {
    assert(test() === 42)
  }
  bench.end(runs)
}
