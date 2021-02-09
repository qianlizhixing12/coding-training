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
  int prev;
  int count;
  int max;

  void inorder(TreeNode *root, vector<int> &ans) {
    if (root == NULL) {
      return;
    }
    inorder(root->left, ans);
    if (prev != root->val) {
      count = 1;
    } else {
      count++;
    }
    if (count == max) {
      ans.push_back(root->val);
    } else if (count > max) {
      ans.clear();
      max = count;
      ans.push_back(root->val);
    }
    prev = root->val;
    inorder(root->right, ans);
  }

public:
  vector<int> findMode(TreeNode *root) {
    prev = 0;
    count = 0;
    max = 1;
    vector<int> ans;
    inorder(root, ans);
    return ans;
  }
};