#include <stdlib.h>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    Node dummy(0);
    Node *cur = &dummy;
    // help结构 源节点 -> 对应复制节点
    unordered_map<Node *, Node *> help;
    while (head != NULL) {
      Node *tmp = new Node(head->val);
      cur->next = tmp;
      help[head] = tmp;
      head = head->next;
      cur = cur->next;
    }
    for (auto it = help.begin(); it != help.end(); ++it) {
      if (it->first->random != NULL) {
        it->second->random = help[it->first->random];
      }
    }
    return dummy.next;
  }
};