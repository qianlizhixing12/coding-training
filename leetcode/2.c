#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode sentry = {0, NULL};
  struct ListNode* head = &sentry;

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
    head->next = malloc(sizeof(struct ListNode));
    head = head->next;
    head->val = value % 10;
    head->next = NULL;
    value = value / 10;
  }

  if (value != 0) {
    head->next = malloc(sizeof(struct ListNode));
    head = head->next;
    head->val = value % 10;
    head->next = NULL;
  }

  return sentry.next;
}