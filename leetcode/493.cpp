#include <vector>

using namespace std;

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        // 处理数值太大
        long value = (nums[j] * 2.0);
        if (nums[i] > value) {
          count++;
        }
      }
    }
    return count;
  }
};