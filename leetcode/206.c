#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *result = NULL;
  struct ListNode *tmp = NULL;

  while (head != NULL) {
    tmp = head->next;
    head->next = result;
    result = head;
    head = tmp;
  }

  return result;
}