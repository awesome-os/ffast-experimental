#include <stdio.h>
#include <stdint.h>

typedef int (*callback)(int i, void* j);

callback cb;
int stopped = 1;
int counter = 0;

void register_callback (callback cba) {
  cb = cba;
}

void start_callbacks () {
  stopped = 0;
  counter = 0;
  while (stopped == 0) counter = cb(counter, 0);
}

void stop_callbacks () {
  stopped = 1;
}

void callback_once () {
  counter = cb(counter, cb);
}