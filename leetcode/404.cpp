#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int sumOfLeftLeaves_(TreeNode *root, int dir) {
    if (root == NULL) {
      return 0;
    }
    if (root->left == NULL && root->right == NULL && dir == 0) {
      return root->val;
    }
    return sumOfLeftLeaves_(root->left, 0) + sumOfLeftLeaves_(root->right, 1);
  }

  int sumOfLeftLeaves(TreeNode *root) { return sumOfLeftLeaves_(root, 1); }
};