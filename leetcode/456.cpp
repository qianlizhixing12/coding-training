#include <climits>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  // 暴力解法 O(n**3)
  bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        if (nums[i] >= nums[j]) {
          continue;
        }
        for (int k = j + 1; k < n; k++) {
          if (nums[k] > nums[i] && nums[k] < nums[j]) {
            return true;
          }
        }
      }
    }
    return false;
  }

  // 暴力解法 O(n**2)
  bool find132pattern_(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2) {
      return false;
    }
    for (int i = 0; i < n - 2; i++) {
      int max = nums[i];
      for (int j = i + 1; j < n; j++) {
        if (nums[j] > max) {
          max = nums[j];
        } else if (nums[j] < max && nums[j] > nums[i]) {
          return true;
        }
      }
    }
    return false;
  }
};