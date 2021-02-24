#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
  // 暴力穷举
  int coinChange(vector<int> &coins, int amount) { return dp(coins, amount); }

  int dp(vector<int> &coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    if (amount < 0) {
      return -1;
    }
    int rst = INT_MAX;
    for (auto &coin : coins) {
      int sub = dp(coins, amount - coin);
      if (sub == -1) {
        continue;
      }
      rst = min(rst, sub + 1);
    }
    return rst == INT_MAX ? -1 : rst;
  }
};

class Solution2 {
public:
  // 缓存
  int coinChange(vector<int> &coins, int amount) {
    unordered_map<int, int> cache;
    return dp(cache, coins, amount);
  }

  int dp(unordered_map<int, int> &cache, vector<int> &coins, int amount) {
    if (cache.find(amount) != cache.end()) {
      return cache[amount];
    }
    if (amount == 0) {
      return 0;
    }
    if (amount < 0) {
      return -1;
    }
    int rst = INT_MAX;
    for (auto &coin : coins) {
      int sub = dp(cache, coins, amount - coin);
      if (sub == -1) {
        continue;
      }
      rst = min(rst, sub + 1);
    }
    rst = rst == INT_MAX ? -1 : rst;
    cache[amount] = rst;
    return rst;
  }
};

class Solution3 {
public:
  // 动态规划
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); ++i) {
      for (auto &coin : coins) {
        if (i - coin < 0) {
          continue;
        }
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};