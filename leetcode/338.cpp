#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> result(num + 1, 0);
    // 2**n到2**(n+1)每个数等于2**(n-1)到2**n每个数左移后加0,加1
    for (int i = 1; i <= num; i++) {
      result[i] = result[i >> 1] + (i & 1);
    }
    return result;
  }
};