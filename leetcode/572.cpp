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
private:
  bool isEauql(TreeNode *s, TreeNode *t) {
    if (s == nullptr & t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr || s->val != t->val) {
      return false;
    }
    return isEauql(s->left, t->left) && isEauql(s->right, t->right);
  }

public:
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == nullptr & t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    return isEauql(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};