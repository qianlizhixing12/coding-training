#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  vector<bool> help;
  vector<int> tmp;
  void dfs(vector<int> &nums) {
    if (tmp.size() == nums.size()) {
      ans.emplace_back(tmp);
      return;
    }
    for (int i = 0; i < help.size(); i++) {
      if (help[i] == false ||
          (i > 0 && help[i - 1] == true && nums[i] == nums[i - 1])) {
        continue;
      }
      tmp.emplace_back(nums[i]);
      help[i] = false;
      dfs(nums);
      help[i] = true;
      tmp.pop_back();
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    help = vector<bool>(nums.size(), true);
    sort(nums.begin(), nums.end());
    dfs(nums);
    return ans;
  }
};