#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    map<int, vector<int>> cache;
    for (int i = 0; i < nums.size(); i++) {
      cache[nums[i]].emplace_back(i);
    }
    int count = 0;
    vector<int> ans(nums.size());
    for (pair<int, vector<int>> it : cache) {
      for (int index : it.second) {
        ans[index] = count;
      }
      count += it.second.size();
    }
    return ans;
  }
};