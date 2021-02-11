#include <string>
#include <cstdint>

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
  int dfs(TreeNode *root, int prev) {
    if (root == nullptr) {
      return 0;
    }
    prev = prev * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return prev;
    }
    return dfs(root->left, prev) + dfs(root->right, prev);
  }

public:
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};