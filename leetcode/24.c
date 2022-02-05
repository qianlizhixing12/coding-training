#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {
  struct ListNode sentry = {0, head};
  head = &sentry;

  struct ListNode* tmp1 = NULL;
  struct ListNode* tmp2 = NULL;
  while (head->next != NULL && head->next->next != NULL) {
    tmp1 = head->next;
    tmp2 = head->next->next;
    head->next = tmp2;
    tmp1->next = tmp2->next;
    tmp2->next = tmp1;
    head = tmp1;
  }

  return sentry.next;
}