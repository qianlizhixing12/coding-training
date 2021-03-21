#include <vector>

using namespace std;

class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int n = nums.size();
    int result = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] <= nums[i - 1]) {
        sum = 0;
      }
      sum += nums[i];
      result = max(result, sum);
    }
    return result;
  }
};