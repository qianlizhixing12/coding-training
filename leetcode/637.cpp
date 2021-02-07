#include <vector>
#include <cstdlib>
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
  void dfs(TreeNode *root, vector<double> &sum, vector<int> &count, int level) {
    if (root == NULL) {
      return;
    }
    if (sum.size() < level + 1) {
      sum.push_back(0.0);
      count.push_back(0);
    }
    sum[level] += root->val;
    count[level]++;
    dfs(root->left, sum, count, level + 1);
    dfs(root->right, sum, count, level + 1);
  }

public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> sum;
    vector<int> count;
    dfs(root, sum, count, 0);
    for (int i = 0; i < sum.size(); i++) {
      sum[i] /= count[i];
    }
    return sum;
  }
};