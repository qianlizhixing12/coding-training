#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    //左边界
    int left = 0;
    //右边界
    int right = height.size() - 1;
    int result = 0;
    int temp = 0;
    /** 思路:左右双指针中间夹逼题解
     *  数组 nums
     *  左边界 left  a = nums[left]
     *  右边界 right b = nums[right]
     *  当前面积 （right - left) * min(a, b)
     *  假设a < b(a > b同理)
     *  下一次不管移动left还是right，长度为(right - left - 1),关键看高度
     *  移动left，高度为min(c, b)，c与a比较三种关系都可能存在(<,>,=)
     *  移动right，高度为min(a, c)，c与b比较三种关系都可能存在(<,>,=)
     *  由于a < b，所以min(a, c) <= a，面积一定变小
     *  也就是说，移动高边界，长度一定减小，高度受限于低边界，面积一定减小
     */
    while (left < right) {
      temp = min(height[left], height[right]) * (right - left);
      result = max(result, temp);
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return result;
  }
};

int main() {
  vector<int> temp({1, 8, 6, 2, 5, 4, 8, 3, 7});
  Solution s;
  assert(49 == s.maxArea(temp));
  return 0;
}