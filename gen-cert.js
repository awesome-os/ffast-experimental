import { dump } from './lib/binary.js'
import { generate_cert, create_keypair } from './lib/libssl.js'
import { writeFileSync } from 'node:fs'
import { colors } from './lib/ffast.js'

const { pubkey, privkey, key_ptr } = create_keypair()

const { x509 } = generate_cert(key_ptr, {
  country: 'GB',
  province: 'London',
  city: 'London',
  org: 'billywhizz.io',
  hostname: 'home.billywhizz.io'
})

const { AY, AD } = colors

console.log(`${AY}public key${AD}`)
console.log(dump(pubkey))
console.log(`${AY}private key${AD}`)
console.log(dump(privkey))
console.log(`${AY}x509 cert${AD}`)
console.log(dump(x509))

writeFileSync('cert.pem', x509)
writeFileSync('key.pem', privkey)
