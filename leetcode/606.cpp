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
private:
  void preorder(TreeNode *t, string &val) {
    if (t == NULL) {
      return;
    }
    val += to_string(t->val);
    if (t->left == NULL && t->right == NULL) {
      return;
    }
    val += "(";
    preorder(t->left, val);
    val += ")";
    if (t->right != NULL) {
      val += "(";
      preorder(t->right, val);
      val += ")";
    }
  }

public:
  string tree2str(TreeNode *t) {
    string result = "";
    preorder(t, result);
    return result;
  }
};