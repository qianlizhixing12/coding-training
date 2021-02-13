#include <cstdlib>
#include <unordered_map>
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
  unordered_map<TreeNode *, int> cache_t;
  unordered_map<TreeNode *, int> cache_f;
  int ans;

  int rob_(TreeNode *root, bool parentRob) {
    if (root == NULL) {
      return 0;
    }
    if (parentRob) {
      if (cache_t.find(root) != cache_t.end()) {
        return cache_t[root];
      }
    } else {
      if (cache_f.find(root) != cache_f.end()) {
        return cache_f[root];
      }
    }
    // 当前节点未被偷
    int l = rob_(root->left, false);
    int r = rob_(root->right, false);
    int m = l + r;
    if (!parentRob) {
      // 父节点未被偷, 当前节点被偷
      m = max(m, rob_(root->left, true) + rob_(root->right, true) + root->val);
    }
    ans = max(ans, m);
    if (parentRob) {
      cache_t[root] = m;
    } else {
      cache_f[root] = m;
    }
    return m;
  }

public:
  int rob(TreeNode *root) {
    ans = 0;
    rob_(root, false);
    return ans;
  }
};