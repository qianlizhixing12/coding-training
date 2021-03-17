#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  /**
   * 暴力解法
   */
  int numDistinct(string s, string t) {
    int n_ = t.size();
    int n = s.size();
    if (n_ == 0 || n == 0) {
      return 0;
    }
    int rst = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[0]) {
        if (n_ == 1) {
          rst += 1;
        } else {
          rst += numDistinct(s.substr(i + 1), t.substr(1));
        }
      }
    }
    return rst;
  }
};

class Solution1 {
private:
  unordered_map<string, int> cache;

public:
  /**
   * 记忆备忘录
   */
  int numDistinct(string s, string t) {
    int n_ = t.size();
    int n = s.size();
    if (n_ == 0 || n == 0) {
      return 0;
    }
    string key = s + "-" + t;
    if (cache.find(key) != cache.end()) {
      return cache[key];
    }
    int rst = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[0]) {
        if (n_ == 1) {
          rst += 1;
        } else {
          rst += numDistinct(s.substr(i + 1), t.substr(1));
        }
      }
    }
    cache[key] = rst;
    return cache[key];
  }
};

class Solution2 {
public:
  /**
   * 记忆备忘录，索引
   */
  int dfs(unordered_map<string, int> &cache, string &s, int n, int i, string &t,
          int n_, int i_) {
    if (n_ <= i_ || n <= i) {
      return 0;
    }
    string key = to_string(i) + "-" + to_string(i_);
    if (cache.find(key) != cache.end()) {
      return cache[key];
    }
    int rst = 0;
    while (i < n) {
      if (s[i] == t[i_]) {
        if ((n_ - i_) == 1) {
          rst += 1;
        } else {
          rst += dfs(cache, s, n, i + 1, t, n_, i_ + 1);
        }
      }
      i++;
    }
    cache[key] = rst;
    return cache[key];
  }

  int numDistinct(string s, string t) {
    unordered_map<string, int> cache;
    int n_ = t.size();
    int n = s.size();
    int i = 0;
    int i_ = 0;
    return dfs(cache, s, n, i, t, n_, i_);
  }
};

class Solution3 {
public:
  /**
   * todo 未完成
   * 动态规划
   */
  int dfs(unordered_map<string, int> &cache, string &s, int n, int i, string &t,
          int n_, int i_) {
    if (n_ <= i_ || n <= i) {
      return 0;
    }
    string key = to_string(i) + "-" + to_string(i_);
    if (cache.find(key) != cache.end()) {
      return cache[key];
    }
    int rst = 0;
    while (i < n) {
      if (s[i] == t[i_]) {
        if ((n_ - i_) == 1) {
          rst += 1;
        } else {
          rst += dfs(cache, s, n, i + 1, t, n_, i_ + 1);
        }
      }
      i++;
    }
    cache[key] = rst;
    return cache[key];
  }

  int numDistinct(string s, string t) {
    int n = s.size();
    int n_ = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(n_ + 1, 0));
    for (int i = 0; i < n_ + 1; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n_ + 1; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[n][n_];
  }
};

int main() {
  //   cout << Solution2().numDistinct("ab", "ab") << endl;
  //   cout << Solution().numDistinct("babgbag", "bag") << endl;
  cout << Solution3().numDistinct("rabbbit", "rabbit") << endl;
  return 0;
}