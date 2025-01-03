#!/bin/bash
if ! test -f src/v8-fast-api-calls.h; then
  echo "downloading src.v8-fast-api-calls.h"
  V8_VERSION=$(node -e "console.log(process.versions.v8.substring(0, process.versions.v8.indexOf('-')))")
  URL="https://raw.githubusercontent.com/v8/v8/refs/tags/$V8_VERSION/include/v8-fast-api-calls.h"
  curl -s -L -o src/v8-fast-api-calls.h $URL
fi
node gen.js demo
node gen.js count
node gen.js ffast
node gen.js tcc
node gen.js noop
node gen.js libssl
node-gyp --verbose rebuild
