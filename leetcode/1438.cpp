#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    deque<int> min_;
    deque<int> max_;
    int l = 0;
    int rst = 0;
    for (int r = 0; r < nums.size(); ++r) {
      while (!min_.empty() && min_.back() > nums[r]) {
        min_.pop_back();
      }
      while (!max_.empty() && max_.back() < nums[r]) {
        max_.pop_back();
      }
      min_.push_back(nums[r]);
      max_.push_back(nums[r]);
      while (!max_.empty() && !min_.empty() &&
             max_.front() - min_.front() > limit) {
        if (nums[l] == min_.front()) {
          min_.pop_front();
        }
        if (nums[l] == max_.front()) {
          max_.pop_front();
        }
        ++l;
      }
      rst = max(rst, r - l + 1);
    }
    return rst;
  }
};

int main() {
  vector<int> nums = {8, 2, 4, 7};
  //   vector<int> nums = {1, 5, 6, 7, 8, 10, 6, 5, 6};
  Solution().longestSubarray(nums, 4);
  return 0;
}