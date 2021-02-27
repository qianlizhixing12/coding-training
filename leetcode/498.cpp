#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 0,0 0
// 0,1 1,0 1  正方向
// 0,2 1,1, 2,0 2 负方向
// 1,2, 2,1 3
// 2,2 4

class Solution1 {
public:
  // 模拟操作，从两个方向
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
      return vector<int>();
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int s = m + n - 2;
    vector<int> rst;
    for (int i = 0; i <= s; i++) {
      if (i & 1 == 1) {
        for (int k = 0; k <= i; k++) {
          if (k < m && i - k < n) {
            rst.emplace_back(matrix[k][i - k]);
          }
        }
      } else {
        for (int k = i; k >= 0; k--) {
          if (k < m && i - k < n) {
            rst.emplace_back(matrix[k][i - k]);
          }
        }
      }
    }
    return rst;
  }
};

class Solution2 {
public:
  // 模拟操作，从两个方向，统一代码
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
      return vector<int>();
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int s = m + n - 2;
    vector<int> rst;
    for (int i = 0; i <= s; i++) {
      bool dir = i & 1 == 1;
      int step = dir ? 1 : -1;
      int k = dir ? 0 : min(i, m - 1);
      int compare = dir ? min(m, i + 1) : 0;
      auto f = [&]() { return dir ? k < compare : k >= compare; };
      for (; f(); k = k + step) {
        if (i - k < n) {
          rst.emplace_back(matrix[k][i - k]);
        }
      }
    }
    return rst;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution2().findDiagonalOrder(matrix);
  return 0;
}