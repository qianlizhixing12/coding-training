#include <cstdlib>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int depthOfNode(TreeNode *root, int &ans) {
    if (root == NULL) {
      return 0;
    }
    int l = depthOfNode(root->left, ans);
    int r = depthOfNode(root->right, ans);
    ans = max(ans, l + r);
    return max(l, r) + 1;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    depthOfNode(root, ans);
    return ans;
  }
};