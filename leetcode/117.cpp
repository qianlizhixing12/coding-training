#include <cstdlib>
#include <queue>

using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == NULL) {
      return root;
    }
    queue<Node *> cache;
    cache.push(root);
    while (!cache.empty()) {
      int len = cache.size();
      Node *next = NULL;
      for (int i = 0; i < len; i++) {
        Node *cur = cache.front();
        cur->next = next;
        next = cur;
        cache.pop();
        if (cur->right != NULL) {
          cache.push(cur->right);
        }
        if (cur->left != NULL) {
          cache.push(cur->left);
        }
      }
    }
    return root;
  }
};

int main() {
  Node l = Node(2);
  Node r = Node(3);
  Node root = Node(1, &l, &r, NULL);
  Solution().connect(&root);
  return 0;
}