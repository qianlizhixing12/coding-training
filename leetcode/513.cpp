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
  void inorder(TreeNode *root, int depth, int &maxdepth, int &val) {
    if (root == nullptr) {
      return;
    }
    depth++;
    inorder(root->left, depth, maxdepth, val);
    inorder(root->right, depth, maxdepth, val);
    if (depth > maxdepth) {
      maxdepth = depth;
      val = root->val;
    }
  }

public:
  int findBottomLeftValue(TreeNode *root) {
    int maxdepth = 0;
    int val = 0;
    inorder(root, 0, maxdepth, val);
    return val;
  }
};