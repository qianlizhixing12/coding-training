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
  void preorder(TreeNode *root, vector<int> &data) {
    if (root == nullptr) {
      return;
    }
    preorder(root->left, data);
    data.push_back(root->val);
    preorder(root->right, data);
  }

public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> data1;
    vector<int> data2;
    preorder(root1, data1);
    preorder(root2, data2);
    vector<int> ans(data1.size() + data2.size());
    int p1 = 0;
    int p2 = 0;
    int p = 0;
    while (p1 < data1.size() && p2 < data2.size()) {
      if (data1[p1] <= data2[p2]) {
        ans[p++] = data1[p1++];
      } else {
        ans[p++] = data2[p2++];
      }
    }
    while (p1 < data1.size()) {
      ans[p++] = data1[p1++];
    }
    while (p2 < data2.size()) {
      ans[p++] = data2[p2++];
    }
    return ans;
  }
};