#include <vector>

using namespace std;

class Solution1 {
public:
  // 暴力解法
  int fib(int n) {
    if (n <= 1) {
      return n;
    }
    return fib(n - 1) + fib(n - 2);
  }
};

class Solution2 {
public:
  // 带缓存(备忘录)
  int fib(int n) {
    vector<int> cache(max(n + 1, 3), 0);
    cache[1] = 1;
    cache[2] = 1;
    return help(cache, n);
  }

  int help(vector<int> &cache, int n) {
    if (n <= 2 || cache[n] != 0) {
      return cache[n];
    }
    cache[n] = help(cache, n - 1) + help(cache, n - 2);
    return cache[n];
  }
};

class Solution3 {
public:
  // 自底向上 动态规划
  int fib(int n) {
    vector<int> cache(max(n + 1, 3), 0);
    cache[1] = cache[2] = 1;
    for (int i = 3; i < n + 1; i++) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }
    return cache[n];
  }
};

class Solution4 {
public:
  // 自底向上 动态规划
  // 当前状态只和之前的两个状态有关
  int fib(int n) {
    if (n <= 1) {
      return n;
    }
    int num1 = 0;
    int num2 = 1;
    for (int i = 2; i < n + 1; i++) {
      int tmp = num1 + num2;
      num1 = num2;
      num2 = tmp;
    }
    return num2;
  }
};