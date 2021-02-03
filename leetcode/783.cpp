#include <iostream>
#include <stdlib.h>
#include <limits>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int ans = INT32_MAX;
  TreeNode *prev = NULL;

  void recursion(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    // 二差搜索树，中序遍历 从小到大输出
    recursion(root->left);
    if (prev != NULL) {
      ans = min(ans, root->val - prev->val);
    }
    prev = root;
    recursion(root->right);
  }

public:
  int minDiffInBST(TreeNode *root) {
    recursion(root);
    return ans;
  }

  int minDiffInBST_(TreeNode *root) {
    // 暴力解法
    vector<int> nums;
    recursion_(root, nums);

    int ans = INT32_MAX;
    // 可排序优化
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        ans = min(ans, abs(nums[i] - nums[j]));
        if (ans == 1) {
          return ans;
        }
      }
    }
    return ans;
  }

  void recursion_(TreeNode *root, vector<int> &nums) {
    if (root == NULL) {
      return;
    }
    nums.push_back(root->val);
    recursion_(root->left, nums);
    recursion_(root->right, nums);
  }
};