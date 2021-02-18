#include <vector>

using namespace std;

class Solution {
public:
  // 时间复杂度O(nK)
  int minKBitFlips_(vector<int> &A, int K) {
    int rst = 0;
    int start = 0;

    while (start + K <= A.size()) {
      if (!A[start]) {
        rst++;
        for (int i = 0; i < K; i++) {
          A[start + i] = !A[start + i];
        }
      }
      start++;
    }

    bool ok = true;
    for (int i = start; i < A.size(); i++) {
      ok &= A[i];
    }

    return ok ? rst : -1;
  }

  int minKBitFlips(vector<int> &A, int K) {
    int n = A.size();
    vector<int> diff(n + 1);
    int ans = 0, revCnt = 0;
    for (int i = 0; i < n; ++i) {
      revCnt ^= diff[i];
      if (A[i] == revCnt) { // A[i] ^ revCnt == 0
        if (i + K > n) {
          return -1;
        }
        ++ans;
        revCnt ^= 1;
        diff[i + K] ^= 1;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> A = {0, 0, 0, 1, 0, 1, 1, 0};
  Solution().minKBitFlips(A, 3);
  return 1;
}
