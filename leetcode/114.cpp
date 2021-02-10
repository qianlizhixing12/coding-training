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
  void preorder(TreeNode *root, vector<TreeNode *> &cache) {
    if (root == nullptr) {
      return;
    }
    cache.push_back(root);
    preorder(root->left, cache);
    preorder(root->right, cache);
  }

public:
  void flatten(TreeNode *root) {
    vector<TreeNode *> cache;
    preorder(root, cache);
    for (int i = 0; i < cache.size(); i++) {
      cache[i]->left = nullptr;
      cache[i]->right = i == cache.size() - 1 ? nullptr : cache[i + 1];
    }
  }
};