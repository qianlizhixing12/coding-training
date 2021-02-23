#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    for (int i = 0; i < A.size(); i++) {
      int l = 0;
      int r = A[i].size() - 1;
      while (l < r) {
        int tmp = A[i][l] ^ 1;
        A[i][l] = A[i][r] ^ 1;
        A[i][r] = tmp;
        l++;
        r--;
      }
      if (l == r) {
        A[i][l] ^= 1;
      }
    }
    return A;
  }
};