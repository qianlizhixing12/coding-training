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
  void dfs(TreeNode *root, int min, int &ans) {
    // 左右节点同时存在或不存在
    if (root == nullptr) {
      return;
    }
    if (min == ans && min != root->val) {
      ans = root->val;
    }
    if (min != root->val && ans > root->val) {
      ans = root->val;
    }
    if (root->left == nullptr) {
      return;
    }
    dfs(root->left, min, ans);
    dfs(root->right, min, ans);
  }

public:
  int findSecondMinimumValue(TreeNode *root) {
    if (root == nullptr || root->left == nullptr) {
      return -1;
    }
    int ans = root->val;
    dfs(root, root->val, ans);
    return ans != root->val ? ans : -1;
  }
};