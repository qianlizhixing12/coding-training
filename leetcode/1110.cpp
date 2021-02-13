#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  bool dfs(TreeNode *root, bool parentExists, unordered_set<int> &cache,
           vector<TreeNode *> &ans) {
    if (root == NULL) {
      return false;
    }
    bool del = cache.find(root->val) != cache.end();
    if (dfs(root->left, !del, cache, ans)) {
      root->left = NULL;
    }
    if (dfs(root->right, !del, cache, ans)) {
      root->right = NULL;
    }
    if (!del && !parentExists) {
      ans.emplace_back(root);
    }
    return del;
  }

public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> cache(to_delete.begin(), to_delete.end());
    vector<TreeNode *> ans;
    dfs(root, false, cache, ans);
    return ans;
  }
};