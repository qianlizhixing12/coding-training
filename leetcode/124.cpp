#include <climits>
#include <iostream>

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
  int ans = INT_MIN;
  int maxPathVal(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int l = max(maxPathVal(root->left), 0);
    int r = max(maxPathVal(root->right), 0);
    ans = max(ans, root->val + l + r);
    // 左右节点最大贡献度加节点值等于节点贡献度
    // 不能左节点+右节点+节点值，因为节点贡献度是给父节点用的，不能构成如下路径
    //   x
    //   |
    //   x
    //  / \ 
    // x   x
    return root->val + max(r, l);
  }

  int maxPathSum(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    maxPathVal(root);
    return ans;
  }
};