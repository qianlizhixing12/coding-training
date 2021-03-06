#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int rst = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int ans = 1;
      for (int j = i; j < n; j++) {
        ans *= nums[j];
        rst = max(rst, ans);
      }
    }
    return rst;
  }

  int maxProduct_(vector<int> &nums) {
    int rst = INT_MIN;
    int ans = 1;
    int dp = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      ans *= nums[i];
      rst = max(rst, ans);
      if (ans == 0) {
        ans = 1;
        dp = INT_MIN;
      } else if (ans < 0 && dp == INT_MIN) {
        dp = ans;
      } else if (ans < 0) {
        rst = max(rst, ans / dp);
      }
    }
    return rst;
  }

  int maxProduct__(vector<int> &nums) {
    int rst = INT_MIN;
    int max_ = 1;
    int min_ = 1;
    for (int val : nums) {
      if (val < 0) {
        int tmp = min_;
        min_ = max_;
        max_ = tmp;
      }
      min_ = min(min_ * val, val);
      max_ = max(max_ * val, val);
      rst = max(rst, max_);
    }
    return rst;
  }
};

int main() {
  vector<int> nums = {2, 3, -2, 4};
  Solution().maxProduct_(nums);
  return 0;
}