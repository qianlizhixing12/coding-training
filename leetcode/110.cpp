#include <iostream>
// #include <stdlib.h>

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
  int bst(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left = bst(root->left) + 1;
    int right = bst(root->right) + 1;
    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return -1;
    } else {
      return max(left, right);
    }
  }

public:
  bool isBalanced(TreeNode *root) { return bst(root) >= 0; }
};