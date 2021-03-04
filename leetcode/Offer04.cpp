#include <vector>

using namespace std;

class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return false;
    }
    int row = matrix.size() - 1;
    int col = matrix[0].size();
    int c = 0;
    while (c < col && row >= 0) {
      int val = matrix[row][c];
      if (val == target) {
        return true;
      } else if (val > target) {
        row--;
      } else {
        c++;
      }
    }
    return false;
  }
};