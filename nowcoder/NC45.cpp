#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

class Solution {
private:
  void dfs(const TreeNode *root, vector<vector<int>> &result) {
    if (root == nullptr) {
      return;
    }
    result[0].push_back(root->val);
    dfs(root->left, result);
    result[1].push_back(root->val);
    dfs(root->right, result);
    result[2].push_back(root->val);
  }

public:
  /**
   *
   * @param root TreeNode类 the root of binary tree
   * @return int整型vector<vector<>>
   */
  vector<vector<int>> threeOrders(TreeNode *root) {
    vector<vector<int>> result({vector<int>(), vector<int>(), vector<int>()});
    dfs(root, result);
    return result;
  }
};