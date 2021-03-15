#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int l = 0;
    int r = n - 1;
    int t = 0;
    int b = n - 1;
    int cur = 1;
    vector<vector<int>> rst(n, vector<int>(n));
    while (true) {
      for (int i = l; i <= r; i++) {
        rst[t][i] = cur++;
      }
      if (++t > b) {
        break;
      }
      for (int i = t; i <= b; i++) {
        rst[i][r] = cur++;
      }
      if (--r < l) {
        break;
      }
      for (int i = r; i >= l; i--) {
        rst[b][i] = cur++;
      }
      if (--b < t) {
        break;
      }
      for (int i = b; i >= t; i--) {
        rst[i][l] = cur++;
      }
      if (++l > r) {
        break;
      }
    }
    return rst;
  }
};

int main() {
  Solution().generateMatrix(4);
  return 0;
}