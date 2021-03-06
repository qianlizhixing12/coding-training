#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> s;
    int n = nums.size();
    vector<int> rst(n);
    for (int i = (n << 1) - 1; i >= 0; i--) {
      int id = i % n;
      while (!s.empty() && s.top() <= nums[id]) {
        s.pop();
      }
      rst[id] = s.empty() ? -1 : s.top();
      s.push(nums[id]);
    }
    return rst;
  }
};

int main() {
  vector<int> nums = {5, 4, 3, 2, 1};
  Solution().nextGreaterElements(nums);
  return 0;
}