#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans(1, vector<int>());
    unordered_map<int, int> help;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      int val = nums[i];
      int len = ans.size();
      int j = help.find(val) == help.end() ? 0 : help[val];
      for (; j < len; j++) {
        vector<int> cur = ans[j];
        cur.emplace_back(val);
        ans.emplace_back(cur);
      }
      help[val] = len;
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 2};
  Solution().subsetsWithDup(nums);
  return 0;
}