#include <vector>
#include <climits>

using namespace std;

class Solution1 {
public:
  //暴力解法
  int minPathSum(vector<vector<int>> &grid) {
    return dp(grid, grid.size(), grid[0].size(), 0, 0);
  }

  int dp(vector<vector<int>> &grid, int x, int y, int r, int c) {
    if (r == x - 1 && c == y - 1) {
      return grid[r][c];
    } else if (r >= x || c >= y) {
      return INT_MAX;
    }
    return min(dp(grid, x, y, r + 1, c), dp(grid, x, y, r, c + 1)) + grid[r][c];
  }
};

class Solution {
public:
  //动态规划
  int minPathSum(vector<vector<int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<int> cache(c);
    cache[0] = grid[0][0];
    for (int i = 1; i < c; i++) {
      cache[i] = cache[i - 1] + grid[0][i];
    }
    for (int i = 1; i < r; i++) {
      cache[0] += grid[i][0];
      for (int j = 1; j < c; j++) {
        cache[j] = min(cache[j - 1], cache[j]) + grid[i][j];
      }
    }
    return cache[c - 1];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution().minPathSum(grid);
  return 0;
}