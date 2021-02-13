#include <vector>

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
  vector<vector<int>> ans;
  vector<int> val;

  void dfs(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return;
    }
    val.emplace_back(root->val);
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr && 0 == targetSum) {
      ans.emplace_back(val);
    }
    if (root->left != nullptr) {
      dfs(root->left, targetSum);
    }
    if (root->right != nullptr) {
      dfs(root->right, targetSum);
    }
    val.pop_back();
  }

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    dfs(root, targetSum);
    return ans;
  }
};