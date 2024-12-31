#!/bin/bash
V8_VERSION=$(node -e "console.log(process.versions.v8.substring(0, process.versions.v8.indexOf('-')))")
URL="https://raw.githubusercontent.com/v8/v8/refs/tags/$V8_VERSION/include/v8-fast-api-calls.h"
curl -s -L -o v8-fast-api-calls.h $URL
node gen.js demo > demo.cc
node gen.js count > count.cc
node gen.js ffast > ffast.cc
node-gyp configure
node-gyp build
/home/andrew/.node/23/bin/node --experimental-sea-config sea-config.json
cp /home/andrew/.node/23/bin/node demo
npx postject demo NODE_SEA_BLOB demo.blob --sentinel-fuse NODE_SEA_FUSE_fce680ab2cc467b6e072b8b5df1996b2
rm -f demo.blob