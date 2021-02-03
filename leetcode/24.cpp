struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs_(ListNode *head) {
    // 哨兵
    ListNode sentry;
    ListNode *result = &sentry;
    ListNode *cur = &sentry;
    ListNode *temp;
    sentry.next = head;
    while (head != nullptr && head->next != nullptr) {
      temp = head->next->next;
      cur->next = head->next;
      head->next->next = head;
      head->next = temp;
      cur = head;
      head = temp;
    }
    return result->next;
  }

  ListNode *swapPairs(ListNode *head) {
    if ((head == nullptr) || (head->next == nullptr)) {
      return head;
    }
    ListNode *ans = head->next;
    head->next = swapPairs(ans->next);
    ans->next = head;
    return ans;
  }
};