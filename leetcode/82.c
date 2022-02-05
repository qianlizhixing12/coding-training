#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
  struct ListNode sentry = {0, head};
  head = &sentry;

  while (head->next != NULL && head->next->next != NULL) {
    if (head->next->val != head->next->next->val) {
      head = head->next;
    } else {
      int flag = head->next->val;
      while (head->next != NULL && head->next->val == flag) {
        head->next = head->next->next;
      }
    }
  }

  return sentry.next;
}