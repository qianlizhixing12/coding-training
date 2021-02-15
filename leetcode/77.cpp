#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine_(int n, int k) {
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++) {
      res.emplace_back(vector<int>({i}));
    }

    while (--k > 0) {
      vector<vector<int>> lev;
      for (vector<int> cur : res) {
        for (int i = cur[cur.size() - 1] + 1; i <= n; i++) {
          lev.emplace_back(cur);
          lev[lev.size() - 1].emplace_back(i);
        }
      }
      res = move(lev);
    }

    return res;
  }

  vector<vector<int>> ans;
  vector<int> help;

  void dfs(int cur, int n, int k) {
    if (help.size() + (n - cur + 1) < k) {
      return;
    }
    if (help.size() == k) {
      ans.emplace_back(help);
      return;
    }

    help.emplace_back(cur);
    dfs(cur + 1, n, k);
    help.pop_back();
    dfs(cur + 1, n, k);
  }

  vector<vector<int>> combine(int n, int k) {
    dfs(1, n, k);
    return ans;
  }
};

int main() {
  // Solution().combine(4, 2);
  Solution().combine(1, 1);
  return 0;
}