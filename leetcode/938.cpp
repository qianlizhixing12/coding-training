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
  int sum = 0;

public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (root == nullptr) {
      return 0;
    }
    if ((root->val >= low) && (root->val <= high)) {
      sum += root->val;
    }
    rangeSumBST(root->left, low, high);
    rangeSumBST(root->right, low, high);
    return sum;
  }

  int rangeSumBST_(TreeNode *root, int low, int high, int sum = 0) {
    if (root == nullptr) {
      return sum;
    }
    if ((root->val >= low) && (root->val <= high)) {
      sum += root->val;
    }
    sum = rangeSumBST_(root->left, low, high, sum);
    sum = rangeSumBST_(root->right, low, high, sum);
    return sum;
  }
};