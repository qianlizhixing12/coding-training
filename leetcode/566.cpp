#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    int r_ = nums.size();
    int c_ = nums[0].size();
    if (r_ == r && c_ == c) {
      return nums;
    }
    if (r_ * c_ != r * c) {
      return nums;
    }
    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int id = i * c + j;
        ans[i][j] = nums[id / c_][id % c_];
      }
    }
    return ans;
  }
};

int main() {
  //   vector<vector<int>> nums = {{1, 2}, {3, 4}};
  //   Solution().matrixReshape(nums, 1, 4);
  vector<vector<int>> nums = {{1, 2, 3, 4}};
  Solution().matrixReshape(nums, 2, 2);
  return 0;
}
