#include <cstdlib>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
  // 内存超过
  void reorderList_(ListNode *head) {
    if (head == NULL) {
      return;
    }
    vector<ListNode *> cache;
    ListNode *tmp = head;
    // int size = 0;
    while (tmp != NULL) {
      cache.emplace_back(tmp);
      tmp = tmp->next;
    }
    int len = cache.size();
    for (int i = 0; i < ((len + 1) >> 1) - 1; i++) {
      if (i != len - 1 - i) {
        cache[i]->next = cache[len - 1 - i];
        cache[len - 1 - i]->next = cache[i + 1];
      } else {
        cache[i]->next = NULL;
      }
    }
  }

  void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
      return;
    }
    // 第一遍循环，快慢指针算出中间位置
    ListNode *s = head;
    ListNode *f = head->next->next;
    ListNode *tmp;
    ListNode *temp;
    while (f != NULL) {
      s = s->next;
      f = f->next;
      if (f != NULL) {
        f = f->next;
      }
    }
    // 慢指针继续第一遍循环，拆成两个链表，第二个反转
    f = s->next;
    s->next = NULL;
    s = NULL;
    while (f != NULL) {
      tmp = f->next;
      f->next = s;
      s = f;
      f = tmp;
    }
    // 第二遍循环，合成最终链表
    f = head;
    while (f != NULL && s != NULL) {
      tmp = f->next;
      temp = s->next;
      f->next = s;
      s->next = tmp;
      f = tmp;
      s = temp;
    }
  }
};

int main() {
  int arr[] = {10, 20, 30, 40, 50};
  ListNode head(arr[0]);
  ListNode *tmp = &head;
  for (int i = 1; i < 5; i++) {
    tmp->next = new ListNode(arr[i]);
    tmp = tmp->next;
  }
  Solution().reorderList(&head);
  return 0;
}