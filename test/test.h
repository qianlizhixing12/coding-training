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

/**
 * @brief   运行测试框架入口主函数
 *
 * @param[in]  argc  参数个数
 * @param[in]  argv  参数值
 * @return  运行结果
 *
 * @note
 *    1 透传main函数入参
 *    2 支持两种运行模式：
 *     2.1 ./main --select 交互式运行测试套测试用例，需用户主动退出
 *     2.2 ./main --all 全量运行测试套测试用例，运行完自动退出
 *           可选参数--save result_file_path 保存运行结果到文件(json格式)
 */
extern int test_case_main(int argc, char **argv);

/**
 * @brief   添加测试用例
 *
 * @param[in]  testsuite  测试套名称
 * @param[in]  testcase  测试用例名称
 * @param[in]  testfun  测试函数，原型参考test_fun
 * @return  void
 *
 * @note
 *    1 添加失败，整个进程退出，退出码参数宏定义
 *    2 testfun内部申请的内存内部释放，测试框架不会释放testfun内部申请的内存
 */
extern void test_case_add(const char *testsuite, const char *testcase,
                          test_fun *testfun);

/**
 * @brief   判断测试预期
 *
 * @param[in]  testcase  测试用例名称
 * @param[in]  line  测试条件在源码中行数
 * @param[in]  result  测试结果
 * @return  void
 *
 * @note
 *    1 不同测试套里面的测试用例名称不能重复，重复会导致运行的测试用例不准确
 *    2 不直接使用该函数，使用封装的宏定义
 *       TEST_CASE_TRUE
 *       TEST_CASE_ARRAY_INT_EQUAL
 *       TEST_CASE_LIST_INT_EQUAL
 */
extern void test_case_assert(const char *testcase, int line, bool result);

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
    if (arr1 == NULL && arr2 == NULL) {                                        \
      test_case_assert(__FUNCTION__, __LINE__, true);                          \
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

#define TEST_CASE_LIST_INT_EQUAL(list1, list2, type_node)                      \
  do {                                                                         \
    type_node _list1 = list1;                                                  \
    type_node _list2 = list2;                                                  \
    do {                                                                       \
      if (_list1 == NULL && _list2 == NULL) {                                  \
        test_case_assert(__FUNCTION__, __LINE__, true);                        \
        break;                                                                 \
      }                                                                        \
      if (_list1 == NULL && _list2 != NULL) {                                  \
        test_case_assert(__FUNCTION__, __LINE__, false);                       \
        break;                                                                 \
      }                                                                        \
      if (_list1 != NULL && _list2 == NULL) {                                  \
        test_case_assert(__FUNCTION__, __LINE__, false);                       \
        break;                                                                 \
      }                                                                        \
      if (_list1->val != _list2->val) {                                        \
        test_case_assert(__FUNCTION__, __LINE__, false);                       \
        break;                                                                 \
      }                                                                        \
      _list1 = _list1->next;                                                   \
      _list2 = _list2->next;                                                   \
    } while (1);                                                               \
  } while (0)

#ifdef __cplusplus
}
#endif
#endif
