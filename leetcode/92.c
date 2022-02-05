#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
  struct ListNode sentry = {0, head};
  head = &sentry;

  // 第一段处理
  for (int i = 1; i < left; ++i) {
    head = head->next;
  }

  // 第二段处理
  struct ListNode* tail = head->next;
  struct ListNode* temp = NULL;
  //   struct ListNode* temp1 = NULL;
  for (int i = left; i < right; ++i) {
    temp = tail->next;
    tail->next = temp->next;
    temp->next = head->next;
    head->next = temp;
  }

  return sentry.next;
}