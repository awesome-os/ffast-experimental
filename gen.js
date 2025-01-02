import { gen_source, gen_gyp } from './lib/gen.js'
import { readFileSync, writeFileSync } from 'node:fs'

const [ name ]  = process.argv.slice(2)
const config = await import (`./${name}.config.js`)
writeFileSync(`src/${name}.cc`, gen_source(config))
const target = gen_gyp(config)
const bindings = JSON.parse(readFileSync('binding.gyp'))
const found = bindings.targets.some(target => {
  if (target.target_name === name) {
    Object.assign(target, target)
    return true
  }
  return false
})
if (!found) bindings.targets.push(target)
writeFileSync('binding.gyp', JSON.stringify(bindings, null, '  '))
