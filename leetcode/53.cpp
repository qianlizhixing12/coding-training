#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  // 暴力解法
  int maxSubArray(vector<int> &nums) {
    int rst = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        rst = max(rst, sum);
      }
    }
    return rst;
  }

  // 动态规划
  int maxSubArray_(vector<int> &nums) {
    int rst = INT_MIN;
    int sum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (sum <= 0) {
        sum = nums[i];
      } else {
        sum += nums[i];
      }
      rst = max(rst, sum);
    }
    return rst;
  }
};