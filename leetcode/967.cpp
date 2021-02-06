#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
private:
  vector<int> result;
  void dfs(int n, int k, int pos, int value) {
    if (pos == n + 1) {
      result.push_back(value);
      return;
    }
    for (int i = 0; i <= 9; i++) {
      // 第一位不能为0
      if (pos == 1) {
        if (i == 0) {
          continue;
        }
        dfs(n, k, pos + 1, i);
      } else {
        if (abs(i - value % 10) == k) {
          dfs(n, k, pos + 1, value * 10 + i);
        }
      }
    }
  }

public:
  // 深度遍历
  vector<int> numsSameConsecDiff(int n, int k) {
    dfs(n, k, 1, 0);
    return result;
  }
};