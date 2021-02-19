#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int repeatedNTimes_(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); i++) {
      if (A[i] == A[i - 1]) {
        return A[i];
      }
    }
  }

  int repeatedNTimes(vector<int> &A) {
    unordered_map<int, int> cache;
    for (int &num : A) {
      cache[num]++;
      if (cache[num] > 1) {
        return num;
      }
    }
    return 0;
  }
};