#include <cstdlib>
#include <vector>
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
  void dfs(TreeNode *root, int parent, int grandparent, int &sum) {
    if (root == nullptr) {
      return;
    }
    if ((grandparent & 1) == 0) {
      sum += root->val;
    }
    dfs(root->left, root->val, parent, sum);
    dfs(root->right, root->val, parent, sum);
  }

public:
  int sumEvenGrandparent(TreeNode *root) {
    int sum = 0;
    dfs(root, 1, 1, sum);
    return sum;
  }
};