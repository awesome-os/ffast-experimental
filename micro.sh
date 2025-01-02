#!/bin/bash
gcc -D_GNU_SOURCE -std=c99 -s -O3 -march=native -mtune=native -o micro-c micro.c