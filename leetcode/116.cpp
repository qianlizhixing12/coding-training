#include <cstdlib>
#include <vector>

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
private:
  void dfs(Node *root, int depth, vector<Node *> &cache) {
    if (root == nullptr) {
      return;
    }
    if (cache.size() <= depth) {
      cache.push_back(NULL);
    }
    root->next = cache[depth];
    cache[depth] = root;
    dfs(root->right, depth + 1, cache);
    dfs(root->left, depth + 1, cache);
  }

public:
  Node *connect(Node *root) {
    vector<Node *> cache;
    dfs(root, 0, cache);
    return root;
  }
};