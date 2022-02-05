#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
  if (k <= 1) {
    return head;
  }

  struct ListNode sentry = {0, head};
  struct ListNode* tail = NULL;
  struct ListNode* temp = NULL;
  head = &sentry;

  while (head != NULL) {
    // 判断是否满足k个
    temp = head;
    for (int i = 0; i <= k; ++i) {
      if (temp != NULL) {
        temp = temp->next;
      } else {
        return sentry.next;
      }
    }

    // k个一组开始交换
    tail = head->next;
    for (int i = 1; i < k; ++i) {
      temp = tail->next;
      tail->next = temp->next;
      temp->next = head->next;
      head->next = temp;
    }

    head = tail;
  }

  return sentry.next;
}

int main(int argc, char* argv[]) {
  struct ListNode tmp1 = {1, NULL};
  struct ListNode tmp2 = {2, NULL};
  struct ListNode tmp3 = {3, NULL};
  struct ListNode tmp4 = {4, NULL};
  struct ListNode tmp5 = {5, NULL};
  tmp1.next = &tmp2;
  tmp2.next = &tmp3;
  tmp3.next = &tmp4;
  tmp4.next = &tmp5;

  reverseKGroup(&tmp1, 2);

  return 0;
}