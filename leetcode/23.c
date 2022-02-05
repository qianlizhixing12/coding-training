#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  struct ListNode sentry = {0, NULL};
  struct ListNode* head = &sentry;
  struct ListNode* temp = NULL;
  const struct ListNode MAX_NODE = {10001, NULL};
  int index;

  while (1) {
    temp = &MAX_NODE;
    index = 0;
    for (int i = 0; i < listsSize; ++i) {
      if (lists[i] != NULL && lists[i]->val < temp->val) {
        temp = lists[i];
        index = i;
      }
    }
    if (temp != &MAX_NODE) {
      head->next = temp;
      head = head->next;
      lists[index] = lists[index]->next;
    } else {
      break;
    }
  }

  return sentry.next;
}