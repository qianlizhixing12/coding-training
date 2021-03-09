#include <string>

using namespace std;

class Solution {
private:
  bool is_palindrom(string &s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }

public:
  string longestPalindrome(string s) {
    // 暴力解法，但是找到结果尽快退出，O(N*N*N)
    int n = s.size();
    // 长度i
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j + i <= n; j++) {
        if (is_palindrom(s, j, i + j - 1)) {
          return s.substr(j, i);
        }
      }
    }
    return "";
  }

  string longestPalindrome_(string s) {
    // 暴力解法，穷举所有结果，O(N*N*N)
    int n = s.size();
    int max_ = 0;
    string rst;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (j - i + 1 > max_ && is_palindrom(s, i, j)) {
          max_ = j - i + 1;
          rst = s.substr(i, max_);
        }
      }
    }
    return rst;
  }

  string longestPalindrome__(string s) {
    // 暴力解法，穷举所有结果，O(N*N*N)
    int n = s.size();
    int max_ = 0;
    string rst;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (j - i + 1 > max_ && is_palindrom(s, i, j)) {
          max_ = j - i + 1;
          rst = s.substr(i, max_);
        }
      }
    }
    return rst;
  }
};

int main() {
  string s = "babad";
  Solution().longestPalindrome(s);
  return 0;
}