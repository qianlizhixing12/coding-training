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
private:
  int find(vector<int> &nums, int start, int end) {
    int index = end + 1;
    for (int i = start + 1; i <= end; i++) {
      if (nums[start] < nums[i]) {
        return i;
      }
    }
    return index;
  }

  TreeNode *order(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(nums[start]);
    if (start < end) {
      int mid = find(nums, start, end);
      root->left = order(nums, start + 1, mid - 1);
      root->right = order(nums, mid, end);
    }
    return root;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    return order(preorder, 0, preorder.size() - 1);
  }
};