#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode *append(ListNode *tail, ListNode *lk) {
    ListNode *end = lk;
    ListNode *start = lk;
    lk = lk->next;
    end->next = nullptr;
    ListNode *temp;
    while (lk != nullptr) {
      temp = lk;
      lk = lk->next;
      temp->next = start;
      start = temp;
    }
    tail->next = start;
    return end;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k < 2) {
      return head;
    }
    // 哨兵
    ListNode sentry;
    ListNode *result = &sentry;
    ListNode *cur = &sentry;

    int i = 1;
    ListNode *start;
    ListNode *temp;
    while (head != nullptr) {
      if (i == 1) {
        start = head;
        head = head->next;
        i++;
      } else if (i < k) {
        head = head->next;
        i++;
      } else if (i == k) {
        temp = head;
        head = head->next;
        temp->next = nullptr;
        i = 1;
        cur = append(cur, start);
      }
    }
    if (i != 1) {
      cur->next = start;
    }

    return result->next;
  }

  ListNode *reverseKGroupByArr(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k < 2) {
      return head;
    }
    // 哨兵
    ListNode sentry;
    ListNode *result = &sentry;
    ListNode *cur = &sentry;
    // 用缓存数组简化问题，减少状态变量的取值
    vector<ListNode *> temp(k);
    int i = 0;
    while (head != nullptr) {
      temp[i++] = head;
      head = head->next;
      if (i == k) {
        for (vector<ListNode *>::reverse_iterator it = temp.rbegin();
             it != temp.rend(); ++it) {
          cur->next = *it;
          cur = cur->next;
        }
        cur->next = nullptr;
        i = 0;
      }
    }
    if (i != 0) {
      cur->next = temp[0];
    }
    return result->next;
  }
};