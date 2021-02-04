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

class Solution {
private:
  struct Info {
    TreeNode *data;
    int depth;
    Info() : data(nullptr), depth(0){};
    Info(TreeNode *p, int d) : data(p), depth(d){};
  };

  Info dfs(TreeNode *root) {
    if (root == nullptr) {
      return Info();
    }
    Info l = dfs(root->left);
    Info r = dfs(root->right);
    if (l.depth == r.depth) {
      return Info(root, l.depth + 1);
    } else {
      return Info(l.depth > r.depth ? l.data : r.data,
                  max(l.depth, r.depth) + 1);
    }
  }

public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) { return dfs(root).data; }
};