#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int len = nums.size();
    int step = k % len;

    if (step == 0) {
      return;
    }

    vector<int> temp(step);
    // 尾部复制，腾出位置
    for (int i = 0; i < step; i++) {
      temp[i] = nums[len + i - step];
    }
    // 依次移动
    for (int i = len - 1; i >= step; i--) {
      nums[i] = nums[i - step];
    }
    // 头部复制
    for (int i = 0; i < step; i++) {
      nums[i] = temp[i];
    }
  }
};