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
  void dfs(TreeNode *root, int depth, vector<int> &cache) {
    if (root == nullptr) {
      return;
    }
    if (cache.size() <= depth) {
      cache.push_back(0);
    }
    cache[depth] += root->val;
    dfs(root->left, depth + 1, cache);
    dfs(root->right, depth + 1, cache);
  }

public:
  int maxLevelSum(TreeNode *root) {
    vector<int> cache;
    dfs(root, 0, cache);
    return max_element(cache.begin(), cache.end()) - cache.begin() + 1;
  }
};