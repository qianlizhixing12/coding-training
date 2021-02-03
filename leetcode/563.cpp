#include <iostream>

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
  int sum = 0;

  int bst(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left = bst(root->left);
    int right = bst(root->right);
    sum += abs(left - right);
    return left + right + root->val;
  }

public:
  int findTilt(TreeNode *root) {
    bst(root);
    return sum;
  }
};