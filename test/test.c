#include "test.h"
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Unit {
  char *name;
  test_fun *fun;
  struct Unit *next;
  struct Unit *prev;
} TestUnit;

typedef struct {
  char *select;
  uint run;
  uint pass;
  uint fail;
} TestProject;

static TestUnit g_unit = {NULL, NULL, &g_unit, &g_unit};
static TestProject g_project = {NULL, 0, 0, 0};

void test_unit_add(const char *name, test_fun *fun) {
  if (name == NULL || name[0] == '\0' || fun == NULL) {
    printf("param is invialid\n");
    return;
  }

  TestUnit *node = malloc(sizeof(TestUnit));
  if (node == NULL) {
    printf("unit malloc fail\n");
    return;
  }

  uint len = strlen(name);
  node->name = malloc(len + 1);
  if (node->name == NULL) {
    printf("name malloc fail\n");
    free(node);
    return;
  }

  if (memcpy(node->name, name, len) == NULL) {
    printf("unit copy fail\n");
    free(node->name);
    free(node);
    return;
  }

  node->fun = fun;
  node->next = &g_unit;
  node->prev = g_unit.prev;

  g_unit.prev->next = node;
  g_unit.prev = node;
}

static void test_unit_free() {
  TestUnit *tmp = g_unit.next;
  while (tmp != &g_unit) {
    TestUnit *next = tmp->next;
    free(tmp->name);
    free(tmp);
    tmp = next;
  }
}

void test_unit_case(int line, bool result) {
  ++g_project.run;
  if (result) {
    ++g_project.pass;
  } else {
    ++g_project.fail;
  }
}

static bool test_unit_select(const char *project) {
  printf("\n-------------------------");
  printf("\nproject %15s test list:", project);

  TestUnit *tmp = g_unit.next;
  uint num = 1;
  while (tmp != &g_unit) {
    printf("\n%d %s", num, tmp->name);
    tmp = tmp->next;
    ++num;
  }

  printf("\nq quit");
  uint select = 0;

  do {
    printf("\nselect num:");

    char input[4] = {0};
    if (scanf("%s", input) != 1) {
      printf("    invialid select");
      continue;
    }

    if (input[0] == 'q' && input[1] == '\0') {
      return false;
    }

    select = atoi(input);
    if (select == 0 || select >= num) {
      printf("    invialid select");
      continue;
    }

    break;
  } while (1);

  --select;
  tmp = g_unit.next;
  while (tmp != &g_unit && select != 0) {
    tmp = tmp->next;
    --select;
  }
  g_project.select = tmp->name;

  return true;
}

static void test_unit_run_select() {
  if (g_project.select == NULL) {
    return;
  }

  g_project.run = g_project.pass = g_project.fail = 0;

  TestUnit *tmp = g_unit.next;
  while (tmp != &g_unit) {
    if (strcmp(g_project.select, tmp->name) == 0) {
      ((test_fun *)(tmp->fun))();
      return;
    }

    tmp = tmp->next;
  }
}

static void test_unit_result(const char *project) {
  printf("\n%s result:", g_project.select);
  printf("\nrun     pass    fail");
  printf("\n%4d    %4d    %4d", g_project.run, g_project.pass, g_project.fail);
}

void test_unit_run(const char *project) {
  while (test_unit_select(project)) {
    test_unit_run_select();
    test_unit_result(project);
  }

  test_unit_free();
}

#ifdef __cplusplus
}
#endif
