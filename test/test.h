#ifndef TEST_H
#define TEST_H

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int uint;
typedef void(test_fun)(void);

#define TEST_UNIT_ADD(fun)                                                     \
  do {                                                                         \
    test_unit_add(#fun, fun);                                                  \
  } while (0)

#define TEST_UNIT_RUN()                                                        \
  do {                                                                         \
    test_unit_run(__FUNCTION__);                                               \
  } while (0)

#define TEST_CASE_TRUE(value)                                                  \
  do {                                                                         \
    if (value) {                                                               \
      test_unit_case(__LINE__, true);                                          \
    } else {                                                                   \
      test_unit_case(__LINE__, false);                                         \
    }                                                                          \
                                                                               \
  } while (0)

extern void test_unit_add(const char *, test_fun *);
extern void test_unit_run(const char *);
extern void test_unit_case(int, bool);

#ifdef __cplusplus
}
#endif
#endif
