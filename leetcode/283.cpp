#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int pos = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[++pos] = nums[i];
      }
      if (pos != i) {
        nums[i] = 0;
      }
    }
  }
};