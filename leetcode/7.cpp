#include <climits>

class Solution {
public:
  int reverse(int x) {
    if (x < 10 && x > -10) {
      return x;
    }
    bool dir = x > 0;
    x = x > 0 ? x : -x;
    long ans = 0;
    while (x > 0) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    ans = ans * (dir ? 1 : -1);
    if (ans < INT_MIN || ans > INT_MAX) {
      return 0;
    }
    return ans;
  }
};