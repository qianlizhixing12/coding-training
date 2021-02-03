#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int len = 0;
    for (int num : nums) {
      if (num != nums[len]) {
        nums[++len] = num;
      }
    }
    return len + 1;
  }
};