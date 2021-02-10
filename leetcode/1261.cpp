#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
private:
  TreeNode *root;
  vector<bool> cache;

  void preorder(TreeNode *root, int val) {
    if (cache.size() < val + 1) {
      cache.resize((val << 1) + 2, false);
    }
    if (root == NULL) {
      return;
    }
    root->val = val;
    cache[val] = true;
    preorder(root->left, (val << 1) + 1);
    preorder(root->right, (val << 1) + 2);
  }

public:
  FindElements(TreeNode *root) : root(root) { preorder(root, 0); }

  bool find(int target) { return cache.size() >= target + 1 && cache[target]; }
};