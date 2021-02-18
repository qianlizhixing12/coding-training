#include <string>
#include <climits>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
  long myAtoi(string s) {
    if (s == "") {
      return 0;
    }
    int start = 0;
    while (s[start] == ' ') {
      start++;
    }
    int d_ = s[start] == '-' ? -1 : 1;
    bool n_ = false;
    long long val = 0;
    int i = s[start] == '-' || s[start] == '+' ? start + 1 : start;
    for (; i < s.size(); i++) {
      if ((s[i] < '0' || s[i] > '9')) {
        if (s[i] == ' ' && !n_) {
          continue;
        }
        break;
      }
      if (s[i] >= '0' && s[i] <= '9') {
        val = val * 10 + (s[i] - '0');
        // val = d_ == 1 ? min(val, (long long)INT_MAX)
        //               : max(val, (long long)INT_MIN);
        val = d_ == 1 ? min(val, (long long)INT_MAX)
                      : min(val, -(long long)INT_MIN);
        n_ = true;
        continue;
      }
    }
    return val * d_;
  }
};

int main() {
  assert(-2147483648 == Solution().myAtoi("-91283472332"));
  assert(3 == Solution().myAtoi("3.14159"));
  return 0;
}