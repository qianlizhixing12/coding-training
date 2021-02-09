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
  void dfs(TreeNode *root, int depth, int &maxDepth, int &sum) {
    if (root == NULL) {
      return;
    }
    depth++;
    if (depth == maxDepth) {
      sum += root->val;
    } else if (depth > maxDepth) {
      maxDepth = depth;
      sum = root->val;
    }
    dfs(root->left, depth, maxDepth, sum);
    dfs(root->right, depth, maxDepth, sum);
  }

public:
  int deepestLeavesSum(TreeNode *root) {
    int maxDepth = 0;
    int sum = 0;
    dfs(root, 0, maxDepth, sum);
    return sum;
  }
};