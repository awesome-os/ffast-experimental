import { Bench } from './lib/bench.js'

const encoder = new TextEncoder()
const hello = encoder.encode('hello')
const len = hello.length

const iter = parseInt(args[0] || '5', 10)
const runs = parseInt(args[1] || '3000000', 10)
const bench = new Bench()

const expected = [ 
  93, 65, 64, 42, 188, 75, 42, 118, 185, 113, 157, 145, 16, 23, 197, 146 
]
Bun.MD5.hash(hello).forEach((v, i) => assert(v === expected[i]))
Bun.MD5.hash('hello').forEach((v, i) => assert(v === expected[i]))

{
  const { hash } = Bun.MD5

  for (let i = 0; i < iter; i++) {
    bench.start('md5-string')
    for (let j = 0; j < runs; j++) {
      assert(hash('hello').length === 16)
    }
    bench.end(runs, len)
  }
}

{
  const { hash } = Bun.MD5

  for (let i = 0; i < iter; i++) {
    bench.start('md5-buffer')
    for (let j = 0; j < runs; j++) {
      assert(hash(hello).length === 16)
    }
    bench.end(runs, len)
  }
}

/*

const expectedsha256 = [ 
  44, 242, 77, 186, 95, 176, 163, 14, 38, 232, 59, 42, 197, 185, 226, 158, 27, 
  22, 30, 92, 31, 167, 66, 94, 115, 4, 51, 98, 147, 139, 152, 36 
]
Bun.SHA256.hash(hello).forEach((v, i) => assert(v === expectedsha256[i]))
Bun.SHA256.hash('hello').forEach((v, i) => assert(v === expectedsha256[i]))

{
  const { hash } = Bun.SHA256

  for (let i = 0; i < iter; i++) {
    bench.start('sha256-string')
    for (let j = 0; j < runs; j++) {
      hash('hello')
    }
    bench.end(runs)
  }
}

{
  const { hash } = Bun.SHA256

  for (let i = 0; i < iter; i++) {
    bench.start('sha256-buffer')
    for (let j = 0; j < runs; j++) {
      hash(hello)
    }
    bench.end(runs)
  }
}
*/
