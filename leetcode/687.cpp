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
  int max_value = 0;
  int dfs(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int ans = 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    if (root->left != nullptr && root->val == root->left->val &&
        root->right != nullptr && root->val == root->right->val) {
      max_value = max(l + 1 + r + 1, max_value);
      ans = max(l + 1, r + 1);
    } else if (root->left != nullptr && root->val == root->left->val) {
      ans = l + 1;
    } else if (root->right != nullptr && root->val == root->right->val) {
      ans = r + 1;
    }
    max_value = max(ans, max_value);
    return ans;
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    max_value = 0;
    dfs(root);
    return max_value;
  }
};