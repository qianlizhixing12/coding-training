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

#define TEST_CASE_OK 0
#define TEST_CASE_USR_PARAM_CHECK 10
#define TEST_CASE_USR_NOT_FIND 11
#define TEST_CASE_USR_REPEAT_CREATE 12
#define TEST_CASE_SYS_MEM_ALLOC 20
#define TEST_CASE_SYS_MEM_COPY 21

typedef unsigned int uint;
typedef void(test_fun)(void);

extern void test_case_run();
extern void test_case_add(const char *, const char *, test_fun *);
extern void test_case_assert(const char *, int, bool);

#define TEST_CASE_ADD(fun)                                                     \
  do {                                                                         \
    test_case_add(__FUNCTION__, #fun, fun);                                    \
  } while (0)

#define TEST_CASE_TRUE(value)                                                  \
  do {                                                                         \
    if (value) {                                                               \
      test_case_assert(__FUNCTION__, __LINE__, true);                          \
    } else {                                                                   \
      test_case_assert(__FUNCTION__, __LINE__, false);                         \
    }                                                                          \
                                                                               \
  } while (0)

#define TEST_CASE_ARRAY_INT_EQUAL(arr1, arr1Size, arr2, arr2Size)              \
  do {                                                                         \
    if (arr1Size != arr2Size) {                                                \
      test_case_assert(__FUNCTION__, __LINE__, false);                         \
      break;                                                                   \
    }                                                                          \
    if (arr1 == NULL || arr2 == NULL) {                                        \
      test_case_assert(__FUNCTION__, __LINE__, false);                         \
      break;                                                                   \
    }                                                                          \
    for (int i = 0; i < arr1Size; ++i) {                                       \
      if (arr1[i] != arr2[i]) {                                                \
        test_case_assert(__FUNCTION__, __LINE__, false);                       \
        break;                                                                 \
      }                                                                        \
    }                                                                          \
    test_case_assert(__FUNCTION__, __LINE__, true);                            \
  } while (0)

#ifdef __cplusplus
}
#endif
#endif
