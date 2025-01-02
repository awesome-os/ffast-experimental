#!/bin/bash
gcc -D_GNU_SOURCE -std=c99 -s -O3 -march=native -mtune=native -o micro-c src/micro.c
gcc -fPIC -O3 -march=native -mtune=native -s -shared -o callback.so src/callback.c
#curl -s -L -o src/picohttpparser.h "https://raw.githubusercontent.com/h2o/picohttpparser/master/picohttpparser.h"
#curl -s -L -o src/picohttpparser.c "https://raw.githubusercontent.com/h2o/picohttpparser/master/picohttpparser.c"
gcc -fPIC -O3 -march=native -mtune=native -s -shared -o pico.so src/picohttpparser.c