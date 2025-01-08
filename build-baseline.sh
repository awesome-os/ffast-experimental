#!/bin/bash
LIB_PATH=../lo/lib/sqlite/deps/sqlite/.libs/
INCLUDE_PATH=../lo/lib/sqlite/deps/sqlite
CC=gcc
#$CC -ffast-math -flto -c -O3 -march=native -mtune=native -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -I$INCLUDE_PATH baseline.c -o baseline.o
#$CC -static -flto -s -O3 -march=native -mtune=native -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -o baseline baseline.o $LIB_PATH/sqlite3.o -lm
#$CC -ffast-math -flto -g -c -O3 -march=native -mtune=native -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -I$INCLUDE_PATH baseline.c -o baseline.o
#$CC -static -flto -g -O3 -march=native -mtune=native -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -o baseline baseline.o $LIB_PATH/sqlite3.o -lm
$CC -ffast-math -flto -g -c -march=native -mtune=native -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -I$INCLUDE_PATH baseline.c -o baseline.o
$CC -static -flto -g -march=native -mtune=native -fno-exceptions -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -o baseline baseline.o $LIB_PATH/sqlite3.o -lm
