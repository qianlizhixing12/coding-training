#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    // int[3]放置次数，开始位置，结束位置
    unordered_map<int, int[3]> pos;
    int maxc = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (pos.count(nums[i]) == 0) {
        pos[nums[i]][0] = 0;
        pos[nums[i]][1] = i;
      }
      pos[nums[i]][0]++;
      pos[nums[i]][2] = i;
      maxc = max(maxc, pos[nums[i]][0]);
    }
    int ans = INT_MAX;
    for (unordered_map<int, int[3]>::iterator it = pos.begin(); it != pos.end();
         ++it) {
      if (it->second[0] == maxc) {
        ans = min(ans, it->second[2] - it->second[1] + 1);
      }
    }
    return ans;
  }
};