#include <stdlib.h>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
  vector<TreeNode *> allPossibleFBT(int N) {
    vector<TreeNode *> ans;

    if ((N % 1) == 1) {
      return ans;
    }
    if (N == 1) {
      ans.push_back(new TreeNode(0));
      return ans;
    }

    for (int i = 1; i <= N - 2; i += 2) {
      vector<TreeNode *> left = allPossibleFBT(i);
      vector<TreeNode *> right = allPossibleFBT(N - i - 1);
      for (int j = 0; j < left.size(); ++j) {
        for (int k = 0; k < right.size(); ++k) {
          TreeNode *root = new TreeNode(0);
          root->left = left[j];
          root->right = right[k];
          ans.push_back(root);
        }
      }
    }

    return ans;
  }
};