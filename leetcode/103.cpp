#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  vector<deque<int>> ans;

  void dfs(TreeNode *root, int depth, bool dir) {
    if (root == NULL) {
      return;
    }
    if (ans.size() <= depth) {
      ans.emplace_back(deque<int>());
    }
    if (dir) {
      ans[depth].emplace_back(root->val);
    } else {
      ans[depth].emplace_front(root->val);
    }
    dfs(root->left, depth + 1, !dir);
    dfs(root->right, depth + 1, !dir);
  }

public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    dfs(root, 0, true);
    vector<vector<int>> res(ans.size());
    for (int i = 0; i < ans.size(); i++) {
      res[i].resize(ans[i].size());
      for (int j = 0; j < ans[i].size(); j++) {
        res[i][j] = ans[i][j];
      }
    }
    return res;
  }
};