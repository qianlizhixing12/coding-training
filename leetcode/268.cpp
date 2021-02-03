#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // 位运算 利用性质x ^ x = 0  x ^ 0 = x
  int missingNumber(vector<int> &nums) {
    int miss = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      miss ^= i ^ nums[i];
    }
    return miss;
  }
};