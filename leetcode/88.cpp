#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // 从后面向前排序，避免移动
    int pos1 = m - 1;
    int pos2 = n - 1;
    int pos = m + n - 1;
    while (pos1 >= 0 && pos2 >= 0) {
      if (nums1[pos1] >= nums2[pos2]) {
        nums1[pos--] = nums1[pos1--];
      } else {
        nums1[pos--] = nums2[pos2--];
      }
    }
    while (pos2 >= 0) {
      nums1[pos--] = nums2[pos2--];
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  Solution().merge(nums1, 3, nums2, 3);
  return 0;
}