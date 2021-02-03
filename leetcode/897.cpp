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
  TreeNode *bst(TreeNode *node, TreeNode *head) {
    if (node == nullptr) {
      return head;
    }
    head = bst(node->left, head);
    node->left = nullptr;
    head->right = node;
    head = head->right;
    head = bst(node->right, head);
    return head;
  }

public:
  TreeNode *increasingBST(TreeNode *root) {
    TreeNode head;
    bst(root, &head);
    return head.right;
  }
};