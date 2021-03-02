#include <vector>
#include <climits>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution1 {
public:
  // 暴力穷举
  int change(int amount, vector<int> &coins) {
    return dp(amount, coins, INT_MAX);
  }

  int dp(int amount, vector<int> &coins, int cur) {
    if (amount == 0) {
      return 1;
    }
    if (amount < 0) {
      return 0;
    }
    int rst = 0;
    for (auto &coin : coins) {
      if (coin > cur) {
        continue;
      }
      rst += dp(amount - coin, coins, coin);
    }
    return rst;
  }
};

class Solution2 {
public:
  // 缓存备忘录
  int change(int amount, vector<int> &coins) {
    if (amount == 0) {
      return 1;
    }
    if (coins.size() == 0 || amount < 0) {
      return 0;
    }
    vector<vector<int>> cache(amount + 1, vector<int>(coins.size(), -1));
    return dp(amount, coins, cache, coins.size() - 1);
  }

  int dp(int amount, vector<int> &coins, vector<vector<int>> &cache, int cur) {
    if (amount == 0) {
      return 1;
    }
    if (amount < 0) {
      return 0;
    }
    if (cache[amount][cur] != -1) {
      return cache[amount][cur];
    }
    int rst = 0;
    for (int i = 0; i < coins.size(); i++) {
      if (i > cur) {
        continue;
      }
      rst += dp(amount - coins[i], coins, cache, i);
    }
    cache[amount][cur] = rst;
    return rst;
  }
};

class Solution3 {
public:
  // 动态规划
  int change(int amount, vector<int> &coins) {
    vector<int> cache(amount + 1, 0);
    cache[0] = 1;
    for (int coin : coins) {
      for (int j = 0; j <= amount; j++) {
        if (j >= coin) {
          cache[j] += cache[j - coin];
        }
      }
    }
    return cache[amount];
  }
};

int main() {
  int amount = 5;
  vector<int> coins = {1, 2, 5};
  Solution2().change(amount, coins);
  return 0;
}