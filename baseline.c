#include <sqlite3.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

int total = 10;
int count = 10000000;

int get_version (sqlite3_stmt* stmt) {
  assert(sqlite3_reset(stmt) == SQLITE_OK);
  if (sqlite3_step(stmt) == SQLITE_ROW) {
    return sqlite3_column_int(stmt, 0);
  }
  assert(sqlite3_finalize(stmt) == SQLITE_OK);
  return 0;
}

void bench (sqlite3_stmt* stmt) {
  float start, end;
  start = (float)clock() / (CLOCKS_PER_SEC / 1000);
  for (int i = 0; i < count; i++) assert(get_version(stmt) == 100);
  end = (float)clock() / (CLOCKS_PER_SEC / 1000);
  printf("time %.0f ms rate %.0f\n", (end - start), count / ((end - start) / 1000));
}

int main (int argc, char** argv) {
  if (argc > 1) total = atoi(argv[1]);
  if (argc > 2) count = atoi(argv[2]);
  sqlite3* db;
  assert(sqlite3_initialize() == 0);
  int flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_NOMUTEX;
  assert(sqlite3_open_v2(":memory:", &db, flags, NULL) == SQLITE_OK);
  sqlite3_stmt* stmt;
  assert(sqlite3_prepare_v2(db, "pragma user_version", -1, &stmt, 0) == SQLITE_OK);
  char *err_msg = 0;
  assert(sqlite3_exec(db, "PRAGMA auto_vacuum = none", 0, 0, &err_msg) == SQLITE_OK);
  assert(sqlite3_exec(db, "PRAGMA temp_store = memory", 0, 0, &err_msg) == SQLITE_OK);
  assert(sqlite3_exec(db, "PRAGMA locking_mode = exclusive", 0, 0, &err_msg) == SQLITE_OK);
  assert(sqlite3_exec(db, "PRAGMA user_version = 100", 0, 0, &err_msg) == SQLITE_OK);
  while (total--) bench(stmt);
  assert(sqlite3_finalize(stmt) == SQLITE_OK);
  assert(sqlite3_close(db) == SQLITE_OK);
}
