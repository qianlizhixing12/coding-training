#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  TreeNode *xparent = nullptr;
  TreeNode *yparent = nullptr;
  int xdepth = 0;
  int ydepth = 0;

  void dfs(TreeNode *root, int x, int y, TreeNode *parent, int k) {
    if (root == nullptr) {
      return;
    }
    if (root->val == x) {
      xparent = parent;
      xdepth = k;
      return;
    } else if (root->val == y) {
      yparent = parent;
      ydepth = k;
      return;
    }
    dfs(root->left, x, y, root, k + 1);
    dfs(root->right, x, y, root, k + 1);
  }

public:
  bool isCousins(TreeNode *root, int x, int y) {
    dfs(root, x, y, nullptr, 0);
    return xparent != yparent && xdepth == ydepth;
  }
};