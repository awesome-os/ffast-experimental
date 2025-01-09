import { dlopen, JSCallback, ptr, CString } from "bun:ffi";

const {
  symbols: { register_callback, start_callbacks, stop_callbacks, callback_once },
  close,
} = dlopen("./callback.so", {
  register_callback: {
    returns: 'void',
    args: ['callback']
  },
  start_callbacks: {
    returns: 'void',
    args: []
  },
  stop_callbacks: {
    returns: 'void',
    args: []
  },
  callback_once: {
    returns: 'void',
    args: []
  },
});

function mem () {
  return process.memoryUsage().rss
}

const on_callback = new JSCallback(
  (counter) => {
    counter += 1
    if (counter === runs) {
      stop_callbacks()
      const elapsed = Date.now() - then
      const rate = Math.floor(runs / (elapsed / 1000))
      const ns_iter = Math.floor((elapsed * 1000000) / runs)
      console.log(`${runs} ${AG}in${AD} ${elapsed} ${AG}ns${AD} = ${rate} ${AY}per/sec${AD} ${ns_iter} ${AY}ns/iter${AD} ${mem()} ${AC}rss${AD}`)
      then = Date.now()
      if (--total) {
        process.nextTick(start_callbacks())
        counter = 0
      }
    }
    return counter
  },
  {
    returns: "int",
    args: ["int"],
  },
);

const AD = '\u001b[0m'  // ANSI Default
const AG = '\u001b[32m' // ANSI Green
const AY = '\u001b[33m' // ANSI Yellow
const AC = '\u001b[36m' // ANSI Cyan

let total = 20
const runs = 30000000
register_callback(on_callback)
let then = Date.now()
start_callbacks()
//  await Bun.sleep(1000)
