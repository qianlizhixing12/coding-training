
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
  int dfs(TreeNode *node, int parent) {
    if (node == nullptr) {
      return parent;
    }
    if (node->right == nullptr) {
      node->val += parent;
    } else {
      node->val += dfs(node->right, parent);
    }
    return dfs(node->left, node->val);
  }

public:
  TreeNode *bstToGst(TreeNode *root) {
    dfs(root, 0);
    return root;
  }
};