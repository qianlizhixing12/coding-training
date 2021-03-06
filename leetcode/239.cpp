#include <vector>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
  /**
   * @brief 优先队列
   *
   * @param nums
   * @param k
   * @return vector<int>
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
      q.emplace(nums[i], i);
    }
    vector<int> rst;
    rst.emplace_back(q.top().first);
    int n = nums.size();
    for (int i = k; i < n; i++) {
      q.emplace(nums[i], i);
      while (q.top().second <= i - k) {
        q.pop();
      }
      rst.emplace_back(q.top().first);
    }
    return rst;
  }

  /**
   * @brief 单调队列
   *
   * @param nums
   * @param k
   * @return vector<int>
   */
  vector<int> maxSlidingWindow_(vector<int> &nums, int k) {
    deque<int> d;
    vector<int> rst;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      while (!d.empty() && nums[d.back()] <= nums[i]) {
        d.pop_back();
      }
      d.push_back(i);
    }
    rst.emplace_back(nums[d.front()]);
    for (int i = k; i < n; i++) {
      while (!d.empty() && nums[d.back()] <= nums[i]) {
        d.pop_back();
      }
      d.push_back(i);
      while (d.front() <= i - k) {
        d.pop_front();
      }
      rst.emplace_back(nums[d.front()]);
    }
    return rst;
  }
};

int main() {
  vector<int> nums = {9, 10, 9, -7, -4, -8, 2, -6};
  Solution().maxSlidingWindow(nums, 5);
  return 0;
}