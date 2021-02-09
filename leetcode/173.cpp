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

void preorder(TreeNode *root, vector<int> &data) {
  if (root == nullptr) {
    return;
  }
  preorder(root->left, data);
  data.push_back(root->val);
  preorder(root->right, data);
}

class BSTIterator {
private:
  vector<int> data;
  int iter;

public:
  BSTIterator(TreeNode *root) {
    preorder(root, data);
    iter = 0;
  }

  int next() { return data[iter++]; }

  bool hasNext() { return iter >= data.size(); }
};