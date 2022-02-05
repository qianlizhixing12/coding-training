#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  struct ListNode sentry = {0, NULL};
  struct ListNode* head = &sentry;

  while (list1 != NULL && list2 != NULL) {
    if (list1->val <= list2->val) {
      head->next = list1;
      list1 = list1->next;
    } else {
      head->next = list2;
      list2 = list2->next;
    }
    head = head->next;
  }

  if (list1 != NULL) {
    head->next = list1;
  }
  if (list2 != NULL) {
    head->next = list2;
  }

  return sentry.next;
}