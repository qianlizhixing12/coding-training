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
    int i = s[start] == '-' || s[start] == '+' ? start + 1 : start;
    long long val = 0;
    for (; i < s.size(); i++) {
      if ((s[i] < '0' || s[i] > '9')) {
        break;
      }
      val = val * 10 + (s[i] - '0');
      val = d_ == 1 ? min(val, (long long)INT_MAX)
                    : min(val, -(long long)INT_MIN);
    }
    return val * d_;
  }
};

int main() {
  assert(-2147483648 == Solution().myAtoi("-91283472332"));
  assert(3 == Solution().myAtoi("3.14159"));
  return 0;
}