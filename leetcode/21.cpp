struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // 哨兵
    ListNode sentry;
    ListNode *result = &sentry;
    ListNode *temp = result;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        temp->next = l1;
        l1 = l1->next;
      } else {
        temp->next = l2;
        l2 = l2->next;
      }
      temp = temp->next;
    }
    temp->next = (l1 != nullptr) ? l1 : l2;
    return result->next;
  }
};