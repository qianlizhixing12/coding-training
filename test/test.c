#include "test.h"
#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Case {
  char *name;
  uint run;
  uint pass;
  uint fail;
  test_fun *fun;
  struct Case *next;
} TestCase;

typedef struct Suite {
  char *name;
  struct Suite *next;
  struct Case *cases;
} TestSuite;

static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
static TestSuite *g_suite = NULL;
static char *g_save = NULL;

static void test_suite_free() {
  TestSuite *tmp = g_suite;
  while (tmp != NULL) {
    TestCase *node = tmp->cases;
    while (node != NULL) {
      TestCase *next = node->next;
      free(node->name);
      free(node);
      node = next;
    }

    TestSuite *temp = tmp->next;
    free(tmp->name);
    free(tmp);
    tmp = temp;
  }

  g_suite = NULL;
}

static uint test_suite_append(const char *testsuite, TestSuite *suite) {
  if (g_suite == NULL) {
    g_suite = suite;
    return TEST_CASE_OK;
  }

  if (strcmp(testsuite, g_suite->name) == 0) {
    return TEST_CASE_USR_REPEAT_CREATE;
  }

  TestSuite *tmp = g_suite;
  while (tmp->next != NULL) {
    if (strcmp(testsuite, tmp->next->name) == 0) {
      return TEST_CASE_USR_REPEAT_CREATE;
    }

    tmp = tmp->next;
  }

  tmp->next = suite;

  return TEST_CASE_OK;
}

static uint test_suite_create(const char *testsuite, TestSuite **suite) {
  TestSuite *node = malloc(sizeof(TestSuite));
  if (node == NULL) {
    return TEST_CASE_SYS_MEM_ALLOC;
  }

  int len = strlen(testsuite);
  node->name = malloc(len + 1);
  if (node->name == NULL) {
    free(node);
    return TEST_CASE_SYS_MEM_ALLOC;
  }

  if (memcpy(node->name, testsuite, len + 1) == NULL) {
    free(node->name);
    free(node);
    return TEST_CASE_SYS_MEM_COPY;
  }

  node->next = NULL;
  node->cases = NULL;
  *suite = node;
  return TEST_CASE_OK;
}

static uint test_suite_find(const char *testsuite, TestSuite **suite) {
  TestSuite *tmp = g_suite;
  while (tmp != NULL) {
    if (strcmp(testsuite, tmp->name) == 0) {
      *suite = tmp;
      return TEST_CASE_OK;
    }

    tmp = tmp->next;
  }

  return TEST_CASE_USR_NOT_FIND;
}

static uint test_case_append(TestSuite *suite, const char *testcase,
                             TestCase *cases) {
  if (suite == NULL) {
    return TEST_CASE_USR_NOT_FIND;
  }

  if (suite->cases == NULL) {
    suite->cases = cases;
    return TEST_CASE_OK;
  }

  if (strcmp(testcase, suite->cases->name) == 0) {
    return TEST_CASE_USR_REPEAT_CREATE;
  }

  TestCase *tmp = suite->cases;
  while (tmp->next != NULL) {
    if (strcmp(testcase, tmp->next->name) == 0) {
      return TEST_CASE_USR_REPEAT_CREATE;
    }

    tmp = tmp->next;
  }

  tmp->next = cases;

  return TEST_CASE_OK;
}

static uint test_case_create(const char *testcase, test_fun *testfun,
                             TestCase **cases) {
  TestCase *node = malloc(sizeof(TestCase));
  if (node == NULL) {
    return TEST_CASE_SYS_MEM_ALLOC;
  }

  uint len = strlen(testcase);
  node->name = malloc(len + 1);
  if (node->name == NULL) {
    free(node);
    return TEST_CASE_SYS_MEM_ALLOC;
  }

  if (memcpy(node->name, testcase, len + 1) == NULL) {
    free(node->name);
    free(node);
    return TEST_CASE_SYS_MEM_COPY;
  }

  node->next = NULL;
  node->run = node->pass = node->fail = 0;
  node->fun = testfun;
  *cases = node;

  return TEST_CASE_OK;
}

static uint test_case_find(TestSuite *suite, const char *testcase,
                           TestCase **cases) {
  if (suite == NULL) {
    return TEST_CASE_USR_NOT_FIND;
  }

  if (suite->cases == NULL) {
    return TEST_CASE_USR_NOT_FIND;
  }

  TestCase *tmp = suite->cases;
  while (tmp != NULL) {
    if (strcmp(testcase, tmp->name) == 0) {
      *cases = tmp;
      return TEST_CASE_OK;
    }

    tmp = tmp->next;
  }

  return TEST_CASE_USR_NOT_FIND;
}

static uint test_case_check(const char *testsuite, const char *testcase,
                            test_fun *testfun) {
  if (testsuite == NULL || testsuite[0] == '\0') {
    return TEST_CASE_USR_PARAM_CHECK;
  }

  if (testcase == NULL || testcase[0] == '\0') {
    return TEST_CASE_USR_PARAM_CHECK;
  }

  if (testfun == NULL) {
    return TEST_CASE_USR_PARAM_CHECK;
  }

  return TEST_CASE_OK;
}

void test_case_add(const char *testsuite, const char *testcase,
                   test_fun *testfun) {
  (void)pthread_mutex_lock(&g_lock);

  uint ret = test_case_check(testsuite, testcase, testfun);
  if (ret != TEST_CASE_OK) {
    goto err;
  }

  TestSuite *suite = NULL;
  ret = test_suite_find(testsuite, &suite);
  if (ret == TEST_CASE_USR_NOT_FIND) {
    ret = test_suite_create(testsuite, &suite);
    if (ret != TEST_CASE_OK) {
      goto err;
    }
    ret = test_suite_append(testsuite, suite);
    if (ret != TEST_CASE_OK) {
      goto err;
    }
  } else if (ret != TEST_CASE_OK) {
    goto err;
  }

  TestCase *cases = NULL;
  ret = test_case_find(suite, testcase, &cases);
  if (ret == TEST_CASE_USR_NOT_FIND) {
    ret = test_case_create(testcase, testfun, &cases);
    if (ret != TEST_CASE_OK) {
      goto err;
    }
    ret = test_case_append(suite, testcase, cases);
    if (ret != TEST_CASE_OK) {
      goto err;
    }
  } else if (ret == TEST_CASE_OK) {
    ret = TEST_CASE_USR_REPEAT_CREATE;
    goto err;
  }

  (void)pthread_mutex_unlock(&g_lock);
  return;

err:
  test_suite_free();
  (void)pthread_mutex_unlock(&g_lock);
  exit(ret);
  return;
}

static void test_cases_clear(TestSuite *suite) {
  TestCase *node = suite->cases;
  while (node != NULL) {
    node->run = node->pass = node->fail = 0;
    node = node->next;
  }
}

static void test_cases_run(TestSuite *suite) {
  TestCase *node = suite->cases;
  while (node != NULL) {
    ((test_fun *)(node->fun))();
    node = node->next;
  }
}

static void test_suite_run() {
  TestSuite *tmp = g_suite;
  while (tmp != NULL) {
    test_cases_run(tmp);
    tmp = tmp->next;
  }
}

static void test_case_result(TestSuite *suite, TestCase *cases) {
  printf("result:");
  printf("\n  suite.case                               run     pass    fail");

  char suite_case[40] = {0};
  if (suite != NULL) {
    if (cases != NULL) {
      sprintf(suite_case, "%s.%s%c", suite->name, cases->name, '\0');
      printf("\n  %-40s %-4d    %-4d    %-4d", suite_case, cases->run,
             cases->pass, cases->fail);
    } else {
      TestCase *node = suite->cases;
      while (node != NULL) {
        sprintf(suite_case, "%s.%s%c", suite->name, node->name, '\0');
        printf("\n  %-40s %-4d    %-4d    %-4d", suite_case, node->run,
               node->pass, node->fail);
        node = node->next;
      }
    }
  } else {
    TestSuite *tmp = g_suite;
    while (tmp != NULL) {
      TestCase *node = tmp->cases;
      while (node != NULL) {
        sprintf(suite_case, "%s.%s%c", tmp->name, node->name, '\0');
        printf("\n  %-40s %-4d    %-4d    %-4d", suite_case, node->run,
               node->pass, node->fail);
        node = node->next;
      }
      tmp = tmp->next;
    }
  }
}

static bool test_suite_select() {
  printf("\n-------------------------");
  printf("\nsuite list:");

  TestSuite *tmp = g_suite;
  uint num = 1;
  while (tmp != NULL) {
    printf("\n  %d: %s", num, tmp->name);
    test_cases_clear(tmp);
    tmp = tmp->next;
    ++num;
  }
  printf("\n  a: all");
  printf("\n  q: quit");

  uint select = 0;
  do {
    printf("\nsuite select:");
    char input[4] = {0};
    if (scanf("%s", input) != 1) {
      printf("    invialid select");
      continue;
    }

    if (input[0] == 'q' && input[1] == '\0') {
      return false;
    }

    if (input[0] == 'a' && input[1] == '\0') {
      test_suite_run();
      test_case_result(NULL, NULL);
      return true;
    }

    select = atoi(input);
    if (select == 0 || select >= num) {
      printf("    invialid select");
      continue;
    }

    break;
  } while (1);

  --select;
  tmp = g_suite;
  while (tmp != NULL && select != 0) {
    tmp = tmp->next;
    --select;
  }

  printf("suite %s case list:", tmp->name);

  TestCase *temp = tmp->cases;
  uint cnum = 1;
  while (temp != NULL) {
    printf("\n  %d: %s", cnum, temp->name);
    temp = temp->next;
    ++cnum;
  }
  printf("\n  a: all");
  printf("\n  r: return");

  uint cselect = 0;
  do {
    printf("\ncase select:");
    char input[4] = {0};
    if (scanf("%s", input) != 1) {
      printf("    invialid select");
      continue;
    }

    if (input[0] == 'r' && input[1] == '\0') {
      return true;
    }

    if (input[0] == 'a' && input[1] == '\0') {
      test_cases_run(tmp);
      test_case_result(tmp, NULL);
      return true;
    }

    cselect = atoi(input);
    if (cselect == 0 || cselect >= cnum) {
      printf("    invialid select");
      continue;
    }

    break;
  } while (1);

  --cselect;
  temp = tmp->cases;
  while (temp != NULL && cselect != 0) {
    temp = temp->next;
    --cselect;
  }
  ((test_fun *)(temp->fun))();
  test_case_result(tmp, temp);

  return true;
}

static void test_case_run_select() {
  (void)pthread_mutex_lock(&g_lock);

  while (test_suite_select()) {
  }

  test_suite_free();
  (void)pthread_mutex_unlock(&g_lock);
}

static void test_case_result_save() {
  if (g_save == NULL) {
    return;
  }

  FILE *fp = fopen(g_save, "w");
  if (fp == NULL) {
    return;
  }

  int total_run = 0;
  int total_pass = 0;
  int total_fail = 0;
  fputc('{', fp);

  TestSuite *tmp = g_suite;
  while (tmp != NULL) {
    TestCase *node = tmp->cases;
    while (node != NULL) {
      fprintf(fp, "\"%s.%s\":{\"run\":%d,\"pass\":%d,\"fail\":%d},", tmp->name,
              node->name, node->run, node->pass, node->fail);
      total_run += node->run;
      total_pass += node->pass;
      total_fail += node->fail;
      node = node->next;
    }
    tmp = tmp->next;
  }

  fprintf(fp, "\"total_run\":%d,\"total_pass\":%d,\"total_fail\":%d", total_run,
          total_pass, total_fail);

  fputc('}', fp);
  fclose(fp);
}

static void test_case_run_all() {
  (void)pthread_mutex_lock(&g_lock);

  test_suite_run();
  test_case_result(NULL, NULL);
  test_case_result_save();

  test_suite_free();
  (void)pthread_mutex_unlock(&g_lock);
}

void test_case_assert(const char *testcase, int line, bool result) {
  TestSuite *tmp = g_suite;
  while (tmp != NULL) {
    TestCase *cases = NULL;
    uint ret = test_case_find(tmp, testcase, &cases);
    if (ret == TEST_CASE_OK) {
      ++cases->run;
      if (result) {
        ++cases->pass;
      } else {
        ++cases->fail;
      }
    }

    tmp = tmp->next;
  }
}

int test_case_main(int argc, char **argv) {
  if (argc < 2) {
    printf("./main --select/--all [--save result_file_path]");
    return TEST_CASE_USR_PARAM_CHECK;
  }

  if (strcmp(argv[1], "--select") == 0) {
    if (argc > 2) {
      printf("./main --select");
      return TEST_CASE_USR_PARAM_CHECK;
    }

    test_case_run_select();
    return TEST_CASE_OK;
  }

  if (strcmp(argv[1], "--all") == 0) {
    if (argc > 2 && argc != 4) {
      printf("./main --all [--save result_file_path]");
      return TEST_CASE_USR_PARAM_CHECK;
    }
    if (argc == 4 && (strcmp(argv[2], "--save") != 0 || argv[3][0] == '\0')) {
      printf("./main --all [--save result_file_path]");
      return TEST_CASE_USR_PARAM_CHECK;
    }

    g_save = argv[3];
    test_case_run_all();
    return TEST_CASE_OK;
  }

  printf("./main --select/--all [--save result_file_path]");
  return TEST_CASE_USR_PARAM_CHECK;
}

#ifdef __cplusplus
}
#endif
