struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode *deepcopy(ListNode *src, int tag = 0) {
    ListNode head = ListNode();
    ListNode *cur = &head;
    while (src != nullptr) {
      cur->next = new ListNode(src->val + tag);
      src = src->next;
      cur = cur->next;
      tag = cur->val > 9 ? 1 : 0;
      cur->val %= 10;
    }
    if (tag == 1) {
      cur->next = new ListNode(1);
    }
    return head.next;
  }

  ListNode *recursion(ListNode *l1, ListNode *l2, int tag = 0) {
    if (l1 == nullptr) {
      return deepcopy(l2, tag);
    }
    if (l2 == nullptr) {
      return deepcopy(l1, tag);
    }
    ListNode *result = new ListNode(l1->val + l2->val + tag);
    result->next = recursion(l1->next, l2->next, result->val > 9 ? 1 : 0);
    result->val %= 10;
    return result;
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return recursion(l1, l2);
  }

  ListNode *addTwoNumbers_(ListNode *l1, ListNode *l2) {
    ListNode result;
    ListNode *cur = &result;
    int temp = 0;
    while ((l1 != nullptr) || (l2 != nullptr)) {
      if (l1 != nullptr) {
        temp += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        temp += l2->val;
        l2 = l2->next;
      }
      cur->next = new ListNode(temp % 10);
      cur = cur->next;
      temp /= 10;
    }
    if (temp != 0) {
      cur->next = new ListNode(temp % 10);
    }
    return result.next;
  }
};