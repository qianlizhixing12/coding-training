#include <vector>

using namespace std;

class Solution {
public:
  bool isToeplitzMatrix_(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    // 向右方向
    for (int i = 0; i < col - 1; ++i) {
      int val = matrix[0][i];
      for (int j = 1; j < row && i + j < col; ++j) {
        if (val != matrix[j][i + j]) {
          return false;
        }
      }
    }
    // 向下方向
    for (int i = 1; i < row - 1; ++i) {
      int val = matrix[i][0];
      for (int j = i + 1; j < row && j - i < col; ++j) {
        if (val != matrix[j][j - i]) {
          return false;
        }
      }
    }
    return true;
  }

  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    // 判断除去第一行第一列，其他元素是否和左上对角线元素相等
    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        if (matrix[i][j] != matrix[i - 1][j - 1]) {
          return false;
        }
      }
    }
    return true;
  }
};