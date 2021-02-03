#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *result = NULL;
    ListNode *temp;

    while (head != NULL) {
      temp = head->next;
      head->next = result;
      result = head;
      head = temp;
    }

    return result;
  }
};