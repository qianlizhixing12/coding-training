#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1]) {
        return nums[i];
      }
    }
    return -1;
  }

  int findRepeatNumber1(vector<int> &nums) {
    unordered_set<int> cache;
    for (int num : nums) {
      if (cache.count(num) > 0) {
        return num;
      }
      cache.emplace(num);
    }
    return -1;
  }
};