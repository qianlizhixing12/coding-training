#include "leetcode.h"
#include <stdlib.h>

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode sentry = {0, NULL};
  struct ListNode *cur = &sentry;

  // 进位标志
  int value = 0;
  while (l1 != NULL || l2 != NULL) {
    if (l1 != NULL) {
      value += l1->val;
      l1 = l1->next;
    }

    if (l2 != NULL) {
      value += l2->val;
      l2 = l2->next;
    }

    // 不破坏l1 l2结构
    cur->next = malloc(sizeof(struct ListNode));
    cur = cur->next;
    cur->next = NULL;
    if (value >= 10) {
      cur->val = value - 10;
      value = 1;
    } else {
      cur->val = value;
      value = 0;
    }
  }

  if (value != 0) {
    cur->next = malloc(sizeof(struct ListNode));
    cur = cur->next;
    cur->next = NULL;
    cur->val = value;
  }

  return sentry.next;
}