#include <vector>
#include <algorithm>

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
  void dfs(TreeNode *root, int value) {
    if (root == nullptr) {
      return;
    }
    value = value << 1 | root->val;
    if (root->left == nullptr && root->right == nullptr) {
      sum += value;
      return;
    }
    dfs(root->left, value);
    dfs(root->right, value);
  }

public:
  int sumRootToLeaf(TreeNode *root) {
    sum = 0;
    dfs(root, 0);
    return sum;
  }
};