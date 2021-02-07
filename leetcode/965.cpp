#include <cstdlib>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  bool dfs(TreeNode *root, TreeNode *parent) {
    if (root == NULL) {
      return true;
    }
    if (parent != NULL && root->val != parent->val) {
      return false;
    }
    return dfs(root->left, root) && dfs(root->right, root);
  }

public:
  bool isUnivalTree(TreeNode *root) { return dfs(root, NULL); }
};