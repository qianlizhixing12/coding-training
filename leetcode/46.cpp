#include <vector>

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
      if (help[i] == false) {
        continue;
      }
      tmp.emplace_back(nums[i]);
      help[i] = false;
      dfs(nums);
      help[i] = true;
      tmp.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    help = vector<bool>(nums.size(), true);
    dfs(nums);
    return ans;
  }
};