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
public:
  TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    if (root == nullptr || root->val < val) {
      TreeNode *cur = new TreeNode(val);
      cur->left = root;
      return cur;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }
};