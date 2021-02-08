#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int min_diff = INT_MAX;
  void dfs(TreeNode *root, int &val) {
    if (root == NULL) {
      return;
    }
    dfs(root->left, val);
    if (val != -1) {
      min_diff = min(min_diff, root->val - val);
    }
    val = root->val;
    dfs(root->right, val);
  }

public:
  int getMinimumDifference(TreeNode *root) {
    min_diff = INT_MAX;
    int prev = -1;
    dfs(root, prev);
    return min_diff;
  }
};