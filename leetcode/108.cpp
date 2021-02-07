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
  TreeNode *dfs(vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = (right + left + 1) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = dfs(nums, left, mid - 1);
    root->right = dfs(nums, mid + 1, right);
    return root;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if ((nums.size() & 1) == 0) {
      return nullptr;
    }
    return dfs(nums, 0, nums.size() - 1);
  }
};

int main() {
  vector<int> param({-10, -3, 0, 5, 9});
  TreeNode *rst = Solution().sortedArrayToBST(param);
  return 0;
}