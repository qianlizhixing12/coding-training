#include <vector>
#include <queue>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  struct Node {
    int val;
    ListNode *ptr;
    Node(int x, ListNode *p) : val(x), ptr(p) {}
    bool operator<(const Node &n) const { return val > n.val; }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<Node> cache;
    for (ListNode *node : lists) {
      if (node != nullptr) {
        cache.emplace(Node(node->val, node));
      }
    }
    ListNode sentry;
    ListNode *cur = &sentry;
    while (!cache.empty()) {
      const Node tmp = cache.top();
      cache.pop();
      cur->next = tmp.ptr;
      cur = cur->next;
      if (tmp.ptr->next != nullptr) {
        cache.push({tmp.ptr->next->val, tmp.ptr->next});
      }
    }
    return sentry.next;
  }
};
