struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // 中规中矩，分三段
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    // 第一段处理
    ListNode start1(0, head);
    head = &start1;
    for (int i = 1; i < left && head != nullptr; i++) {
      head = head->next;
    }
    ListNode *end1 = head;
    if (head == nullptr || head->next == nullptr) {
      return start1.next;
    }
    //第二段
    head = head->next;
    ListNode *start2 = head;
    ListNode *end2 = head;
    for (int i = left; i <= right && head != nullptr; i++) {
      ListNode *tmp = head->next;
      head->next = start2;
      start2 = head;
      head = tmp;
    }
    // 第一第二段连接
    end1->next = start2;
    // 第二第三段连接
    end2->next = head;
    return start1.next;
  }

  // 双指针
  ListNode *reverseBetween_(ListNode *head, int left, int right) {
    ListNode dummy(0, head);
    ListNode *slow = &dummy;
    ListNode *fast = dummy.next;
    for (int i = 1; i < left; i++) {
      slow = slow->next;
      fast = fast->next;
    }
    for (int i = left; i < right; i++) {
      ListNode *cur = fast->next;
      fast->next = cur->next;
      cur->next = slow->next;
      slow->next = cur;
    }
    return dummy.next;
  }
};

int main() {
  ListNode head(5);
  Solution().reverseBetween(&head, 1, 1);
  return 0;
}