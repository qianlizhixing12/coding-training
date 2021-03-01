#include <vector>

using namespace std;

class Solution {
public:
  // 深度优先，每个元素包含的组合找齐，再找下一个
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

class Solution1 {
public:
  // 最简单方法，逐渐加元素
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans = {vector<int>()};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int val = nums[i];
      int len = ans.size();
      for (int j = 0; j < len; j++) {
        vector<int> cur = ans[j];
        cur.emplace_back(val);
        ans.emplace_back(cur);
      }
    }
    return ans;
  }
};