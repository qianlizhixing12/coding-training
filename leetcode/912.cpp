#include <vector>

using std::vector;

class Solution {
public:
  vector<int> sortArray_insertsort1(vector<int> &nums) {
    // 插入排序
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
      int j = i - 1;
      int tmp = nums[i];
      for (; j >= 0; --j) {
        if (nums[j] > tmp) {
          nums[j + 1] = nums[j];
        } else {
          break;
        }
      }
      nums[j + 1] = tmp;
    }
    return nums;
  }

  vector<int> sortArray_insertsort2(vector<int> &nums) {
    // 插入排序
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
      int j = i - 1;
      int tmp = nums[i];
      while (j >= 0 && nums[j] > tmp) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = tmp;
    }
    return nums;
  }
};