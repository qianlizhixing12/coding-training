#include <cstdlib>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    // p, q分布在root两边
    if (((root->val - p->val) ^ (root->val - q->val)) < 0) {
      return root;
    }
    // 分布在左边
    if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    } else {
      return lowestCommonAncestor(root->right, p, q);
    }
  }
};