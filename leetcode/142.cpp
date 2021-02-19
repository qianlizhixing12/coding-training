#include <cstdlib>
#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> cache;
    while (head != NULL) {
      if (cache.count(head) != 0) {
        return head;
      }
      cache.emplace(head);
      head = head->next;
    }
    return NULL;
  }
};