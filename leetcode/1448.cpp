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
  void goodNodes_(TreeNode *root, int maxv, int &count) {
    if (root == nullptr) {
      return;
    }
    if (root->val >= maxv) {
      count++;
      maxv = root->val;
    }
    goodNodes_(root->left, maxv, count);
    goodNodes_(root->right, maxv, count);
  }

public:
  int goodNodes(TreeNode *root) {
    int count = 0;
    goodNodes_(root, INT_MIN, count);
    return count;
  }
};