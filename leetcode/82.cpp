// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode help(0, head);
    ListNode *pre = &help;
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      ListNode *tmp = cur;
      cur = cur->next;
      bool dup = false;
      while (cur != nullptr && tmp->val == cur->val) {
        dup = true;
        cur = cur->next;
      }
      if (dup) {
        pre->next = cur;
      } else {
        pre = pre->next;
      }
    }
    return help.next;
  }

  ListNode *deleteDuplicates_(ListNode *head) {
    ListNode help(0, head);
    ListNode *cur = &help;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      if (cur->next->val == cur->next->next->val) {
        int tmp = cur->next->val;
        while (cur->next != nullptr && cur->next->val == tmp) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }
    return help.next;
  }
};