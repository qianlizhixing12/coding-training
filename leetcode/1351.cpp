#include <vector>

using namespace std;

class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int count = 0;
    int row = grid.size();
    int right = grid[0].size() - 1;
    for (int i = 0; i < row; ++i) {
      for (int j = right; j >= 0; --j) {
        if (grid[i][j] >= 0) {
          count += (right - j) * (row - i);
          right = j;
          break;
        } else {
          if (j == 0) {
            count += (right - j + 1) * (row - i);
            right = -1;
          }
        }
      }
    }
    return count;
  }
};

int main() {
  // vector<vector<int>> grid = {
  //     {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  vector<vector<int>> grid = {{3, 2}, {-3, -3}, {-3, -3}, {-3, -3}};
  Solution().countNegatives(grid);
  return 0;
}