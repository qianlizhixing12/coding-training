struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // 哨兵
    ListNode sentry(0, head);
    ListNode *slow = &sentry;
    ListNode *fast = head;
    for (int i = 0; i < n && fast != nullptr; ++i) {
      fast = fast->next;
    }
    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    if (slow->next != nullptr) {
      slow->next = slow->next->next;
    }
    return sentry.next;
  }
};