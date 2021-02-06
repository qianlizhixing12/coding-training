#include <climits>

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
  bool isValidBSTFun(TreeNode *root, long min, long max) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= min && min != LONG_MIN) {
      return false;
    }
    if (root->val >= max && max != LONG_MIN) {
      return false;
    }
    return isValidBSTFun(root->left, min, root->val) &&
           isValidBSTFun(root->right, root->val, max);
  }

public:
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return isValidBSTFun(root->left, LONG_MIN, root->val) &&
           isValidBSTFun(root->right, root->val, LONG_MIN);
  }
};