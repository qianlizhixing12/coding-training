#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if (root == NULL) {
      return result;
    }
    queue<TreeNode *> level;
    level.push(root);
    while (!level.empty()) {
      int size = level.size();
      vector<int> cache;
      while (size-- > 0) {
        TreeNode *cur = level.front();
        level.pop();
        cache.push_back(cur->val);
        if (cur->left != NULL) {
          level.push(cur->left);
        }
        if (cur->right != NULL) {
          level.push(cur->right);
        }
      }
      result.push_back(cache);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};