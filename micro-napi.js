import { Bench } from './lib/bench.js'
import { openSync, readSync, closeSync } from "node:fs"
import { createRequire } from "node:module"

const { count_avx } = createRequire(import.meta.url)("./build/Release/linecount.node")

async function read_file_huge (file_name) {
  const { 
    assert, ptr, wrap_memory, mmap, madvise,
    MAP_PRIVATE, MAP_ANONYMOUS,
    MADV_HUGEPAGE, PROT_READ, PROT_WRITE
  } = await import('./lib/ffast.js')
  const memory_flags = MAP_ANONYMOUS | MAP_PRIVATE
  const buf = ptr(readFileSync(file_name))
  const size = 128 * 1024
  const buf_ptr = assert(mmap(0, size, PROT_READ | PROT_WRITE, memory_flags, -1, 0))
  assert(madvise(buf_ptr, size, MADV_HUGEPAGE) === 0)
  const dest = new Uint8Array(wrap_memory(buf_ptr, size, 1))
  dest.set(buf, 0)
  return dest
}

function read_file (file_name) {
  const buf = new Uint8Array(2 * 1024 * 1024)
  const fd = openSync(file_name)
  const bytes = readSync(fd, buf)
  closeSync(fd)
  return buf.slice(0, bytes)
}

const file_name = args[1] || '/dev/shm/test.log'
const buf = await (globalThis.Bun ? read_file : read_file_huge)(file_name)
const runs = 1000000
const expected = count_avx(buf, 10, buf.length)
console.log(`bytes ${buf.length}`)
console.log(`lines ${expected}`)

const bench = new Bench()
for (let j = 0; j < 10; j++) {
  bench.start('count_avx')
  for (let i = 0; i < runs; i++) {
    assert(count_avx(buf, 10, buf.length) === expected)
  }
  bench.end(runs, buf.length)
}
