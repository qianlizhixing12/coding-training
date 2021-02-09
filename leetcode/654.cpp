#include <vector>
#include <algorithm>

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
  int max(vector<int> &nums, int begin, int end) {
    int index = begin;
    for (int i = begin + 1; i <= end; i++) {
      if (nums[i] > nums[index]) {
        index = begin;
      }
    }
    return index;
  }
  TreeNode *dfs(vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = max(nums, begin, end);
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = dfs(nums, begin, mid - 1);
    root->right = dfs(nums, mid + 1, end);
    return root;
  }

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return dfs(nums, 0, nums.size() - 1);
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 6, 0, 5};
  TreeNode *tree = Solution().constructMaximumBinaryTree(nums);
  return 0;
}