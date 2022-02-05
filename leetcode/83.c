#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode* cur = head;

  while (cur->next != NULL) {
    if (cur->val == cur->next->val) {
      cur->next = cur->next->next;
    } else {
      cur = cur->next;
    }
  }

  return head;
}