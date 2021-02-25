#include <vector>

using namespace std;

class Solution1 {
public:
  // 暴力
  int climbStairs(int n) {
    if (n == 0) {
      return 1;
    }
    if (n < 0) {
      return 0;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

class Solution2 {
public:
  // 缓冲备忘录
  int climbStairs(int n) {
    vector<int> cache(n + 1, 0);
    cache[0] = 1;
    dp(n, cache);
    return cache[n];
  }

  int dp(int n, vector<int> &cache) {
    if (n < 0) {
      return 0;
    }
    if (cache[n] != 0) {
      return cache[n];
    }
    cache[n] = dp(n - 1, cache) + dp(n - 2, cache);
    return cache[n];
  }
};

class Solution3 {
public:
  //动态规划
  int climbStairs(int n) {
    vector<int> cache(n + 1, 0);
    cache[0] = 1;
    for (int i = 1; i <= n; i++) {
      cache[i] += cache[i - 1];
      if (i > 1) {
        cache[i] += cache[i - 2];
      }
    }
    return cache[n];
  }
};

class Solution4 {
public:
  //动态规划,优化空间
  int climbStairs(int n) {
    int num1 = 1;
    int num2 = 1;
    for (int i = 2; i <= n; i++) {
      int tmp = num1 + num2;
      num1 = num2;
      num2 = tmp;
    }
    return num2;
  }
};

int main() {
  Solution2().climbStairs(3);
  return 0;
}