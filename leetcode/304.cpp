#include <vector>

using namespace std;

class NumMatrix {
private:
  vector<vector<int>> data;

public:
  NumMatrix(vector<vector<int>> &matrix) {
    int row = matrix.size();
    if (row == 0) {
      return;
    }
    int col = matrix[0].size();
    if (col == 0) {
      return;
    }
    data = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        data[i + 1][j + 1] =
            data[i + 1][j] + data[i][j + 1] - data[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (data.size() == 0 || data[0].size() == 0) {
      return 0;
    }
    return data[row2 + 1][col2 + 1] - data[row2 + 1][col1] -
           data[row1][col2 + 1] + data[row1][col1];
  }
};

int main() {
  vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5}};
  NumMatrix(matrix).sumRegion(2, 1, 4, 3);
  return 0;
}