#include <iostream>

using namespace std;

class Solution {
public:
  int kthGrammar(int N, int K) {
    if (K == 1) {
      return 0;
    }
    if (K == 2) {
      return 1;
    }
    if (N == 1) {
      return 0;
    }
    int k_pre = kthGrammar(N - 1, (K + 1) >> 1);
    if ((k_pre == 0 && K % 2 == 1) || (k_pre == 1 && K % 2 == 0)) {
      return 0;
    } else {
      return 1;
    }
  }
};

int main() {
  // cout << Solution().kthGrammar(3, 3) << endl;
  // cout << Solution().kthGrammar(4, 3) << endl;
  cout << Solution().kthGrammar(4, 6) << endl;
  return 0;
}