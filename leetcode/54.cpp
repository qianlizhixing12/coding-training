#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> rst;
    int d = 0;
    int u = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    while (true) {
      for (int i = l; i <= r; i++) {
        rst.emplace_back(matrix[d][i]);
      }
      if (++d > u) {
        break;
      }
      for (int i = d; i <= u; i++) {
        rst.emplace_back(matrix[i][r]);
      }
      if (--r < l) {
        break;
      }
      for (int i = r; i >= l; i--) {
        rst.emplace_back(matrix[u][i]);
      }
      if (--u < d) {
        break;
      }
      for (int i = u; i >= d; i--) {
        rst.emplace_back(matrix[i][l]);
      }
      if (++l > r) {
        break;
      }
    }
    return rst;
  }
};