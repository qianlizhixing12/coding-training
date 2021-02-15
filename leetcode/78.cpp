#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<bool> &help,
           vector<int> &cur, int pos) {
    ans.emplace_back(cur);
    for (int i = pos; i < nums.size(); i++) {
      if (help[i] == true) {
        continue;
      }
      cur.emplace_back(nums[i]);
      help[i] = true;
      dfs(nums, ans, help, cur, i + 1);
      help[i] = false;
      cur.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<bool> help(nums.size(), false);
    vector<int> cur;
    vector<vector<int>> ans;
    dfs(nums, ans, help, cur, 0);
    return ans;
  }
};