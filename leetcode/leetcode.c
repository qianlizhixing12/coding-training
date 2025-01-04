#include "leetcode.h"

struct ListNode *arrToList(int *arr, uint len) {
  if (arr == NULL || len == 0) {
    return NULL;
  }

  struct ListNode *tmp = NULL;

  for (int i = len - 1; i >= 0; --i) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = arr[i];
    node->next = tmp;
    tmp = node;
  }

  return tmp;
}

void freeList(struct ListNode *list) {
  if (list == NULL) {
    return;
  }

  while (list != NULL) {
    struct ListNode *node = list->next;
    free(list);
    list = node;
  }
}
