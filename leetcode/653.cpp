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
public:
  void inorder(TreeNode *root, vector<int> &data) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left, data);
    data.push_back(root->val);
    inorder(root->right, data);
  }

  bool findTarget(TreeNode *root, int k) {
    vector<int> data;
    inorder(root, data);
    int l = 0;
    int r = data.size() - 1;
    while (l < r) {
      int value = data[l] + data[r];
      if (value == k) {
        return true;
      }
      value < k ? l++ : r--;
    }
    return false;
  }
};