#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
  void dfs(TreeNode *root, vector<bool> &cache, int &ans) {
    if (root == nullptr) {
      return;
    }
    cache[root->val] = !cache[root->val];
    if (root->left == nullptr && root->right == nullptr) {
      if (count(cache.begin(), cache.end(), true) <= 1) {
        ans++;
      }
      // 回溯
      cache[root->val] = !cache[root->val];
      return;
    }
    dfs(root->left, cache, ans);
    dfs(root->right, cache, ans);
    // 回溯
    cache[root->val] = !cache[root->val];
  }

public:
  int pseudoPalindromicPaths(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    vector<bool> cache(10);
    int count = 0;
    dfs(root, cache, count);
    return count;
  }
};