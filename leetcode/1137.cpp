#include <vector>

using namespace std;

class Solution {
public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 1;
    }

    int num0 = 0;
    int num1 = 1;
    int num2 = 1;
    int swap;

    for (int i = 3; i <= n; i++) {
      swap = num0 + num1 + num2;
      num0 = num1;
      num1 = num2;
      num2 = swap;
    }

    return num2;
  }

  int recursion(int n, vector<int> &cache) {
    if ((n > 2) && (cache[n] == -1)) {
      cache[n] = recursion(n - 3, cache) + recursion(n - 2, cache) +
                 recursion(n - 1, cache);
    }
    return cache[n];
  }

  int tribonacci_(int n) {
    vector<int> cache(n + 1, -1);
    cache = {0, 1, 1};
    return recursion(n, cache);
  }
};