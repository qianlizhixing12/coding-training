#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (k == 0 || head == NULL || head->next == NULL) {
    return head;
  }

  int n = 1;
  struct ListNode* tmp = head;

  while (tmp->next != NULL) {
    ++n;
    tmp = tmp->next;
  }

  k = n - k % n;
  if (k == n) {
    return head;
  }

  tmp->next = head;
  for (int i = 0; i < k; ++i) {
    tmp = tmp->next;
  }
  head = tmp->next;
  tmp->next = NULL;
  return head;
}