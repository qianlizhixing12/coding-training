#include <cmath>
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
  void dfs(TreeNode *root, int maxv, int minv, int &ans) {
    if (root == nullptr) {
      return;
    }
    maxv = max(maxv, root->val);
    minv = min(minv, root->val);
    if (root->left == nullptr && root->right == nullptr) {
      ans = max(ans, abs(maxv - minv));
      return;
    }
    dfs(root->left, maxv, minv, ans);
    dfs(root->right, maxv, minv, ans);
  }

public:
  int maxAncestorDiff(TreeNode *root) {
    int ans = 0;
    dfs(root, root->val, root->val, ans);
    return ans;
  }
};