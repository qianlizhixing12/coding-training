#include <stdlib.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    if (cloned == NULL) {
      return NULL;
    }
    if (target->val == cloned->val) {
      return cloned;
    }
    TreeNode *left = getTargetCopy(original, cloned->left, target);
    if (left != NULL) {
      return left;
    }
    return getTargetCopy(original, cloned->right, target);
  }

  /**
   * @brief 地址比较，确保多个target情况
   *
   * @param original
   * @param cloned
   * @param target
   * @return TreeNode*
   */
  TreeNode *getTargetCopy_(TreeNode *original, TreeNode *cloned,
                           TreeNode *target) {
    if (original == NULL) {
      return NULL;
    }
    if (target == original) {
      return cloned;
    }
    TreeNode *left = getTargetCopy_(original->left, cloned->left, target);
    if (left != NULL) {
      return left;
    }
    return getTargetCopy_(original->right, cloned->right, target);
  }
};