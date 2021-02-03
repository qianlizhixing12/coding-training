#include <stdlib.h>
#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // 地址作为key键
    unordered_set<ListNode *> help;
    while (head != nullptr) {
      if (help.count(head) > 0) {
        return true;
      }
      help.emplace(head);
      head = head->next;
    }
    return false;
  }

  bool hasCycleOrg(ListNode *head) {
    if (head == NULL) {
      return false;
    }
    // 循环
    ListNode *cur = head;
    ListNode *search;
    while (cur != NULL) {
      search = cur->next;
      while (search != NULL) {
        if (search == cur) {
          return true;
        }
        search = search->next;
      }
      cur = cur->next;
    }
    return false;
  }

  bool hasCycleDoublePtr(ListNode *head) {
    if (head == NULL) {
      return false;
    }
    // 双指针法，跑的快的会在几圈后和跑的慢的相遇
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != NULL && fast != NULL) {
      if (slow == fast || slow == fast->next) {
        return true;
      }
      slow = slow->next;
      fast = fast->next;
      if (fast != NULL) {
        fast = fast->next;
      } else {
        break;
      }
    }
    return false;
  }
};