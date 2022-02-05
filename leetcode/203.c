#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
  struct ListNode sentry = {0, head};
  head = &sentry;

  while (head->next != NULL) {
    if (head->next->val != val) {
      head = head->next;
    } else {
      head->next = head->next->next;
    }
  }

  return sentry.next;
}