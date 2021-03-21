#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    // 空间m+n
    int row = matrix.size();
    if (row == 0) {
      return;
    }
    int col = matrix[0].size();
    vector<bool> r(row, false);
    vector<bool> c(col, false);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          if (!r[i]) {
            for (int k = 0; k < j; k++) {
              matrix[i][k] = 0;
            }
            r[i] = true;
          }
          if (!c[j]) {
            for (int k = 0; k < i; k++) {
              matrix[k][j] = 0;
            }
            c[j] = true;
          }
        } else if (r[i] || c[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }

  void setZeroes_(vector<vector<int>> &matrix) {
    // 空间m+n，可读性更强
    int row = matrix.size();
    if (row == 0) {
      return;
    }
    int col = matrix[0].size();
    vector<bool> r(row, false);
    vector<bool> c(col, false);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          r[i] = true;
          c[j] = true;
        }
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (r[i] || c[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};