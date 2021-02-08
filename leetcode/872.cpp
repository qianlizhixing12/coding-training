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
  void dfs(TreeNode *root, vector<int> &result) {
    if (root == nullptr) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr) {
      result.push_back(root->val);
      return;
    }
    dfs(root->left, result);
    dfs(root->right, result);
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> leaf1;
    vector<int> leaf2;
    dfs(root1, leaf1);
    dfs(root2, leaf2);
    // return equal(leaf1.begin(), leaf1.end(), leaf2.begin(), leaf2.end());
    return leaf1 == leaf2;
  }
};