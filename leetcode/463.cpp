#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          for (vector<int> d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
                grid[x][y] == 0) {
              ans += 1;
            }
          }
        }
      }
    }
    return ans;
  }
};