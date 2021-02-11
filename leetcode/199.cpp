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
  void dfs(TreeNode *root, int depth, vector<int> &ans) {
    if (root == nullptr) {
      return;
    }
    if (ans.size() <= depth) {
      ans.push_back(root->val);
    }
    depth++;
    dfs(root->right, depth, ans);
    dfs(root->left, depth, ans);
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
  }
};