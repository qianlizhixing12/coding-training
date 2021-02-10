#include <iostream>

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

struct Result {
  int depth;
  TreeNode *root;
  Result(int d, TreeNode *r) : depth(d), root(r) {}
};

class Solution {
  Result dfs(TreeNode *root) {
    if (root == nullptr) {
      return Result(0, nullptr);
    }
    Result l = dfs(root->left);
    Result r = dfs(root->right);
    if (l.depth == r.depth) {
      return Result(max(l.depth, r.depth) + 1, root);
    } else {
      return Result(max(l.depth, r.depth) + 1,
                    l.depth > r.depth ? l.root : r.root);
    }
  }

public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root).root; }
};