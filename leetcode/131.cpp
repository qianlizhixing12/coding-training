#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  bool is_palindrome(string &s, int l, int r) {
    if (l == r) {
      return true;
    }
    while (l <= r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }

  void dfs(vector<vector<string>> &rst, string &s, int len, int pos,
           vector<string> &cur) {
    if (pos >= len) {
      rst.emplace_back(cur);
    }
    for (int i = pos; i < len; i++) {
      string tmp = s.substr(pos, i + 1 - pos);
      if (is_palindrome(s, pos, i)) {
        cur.emplace_back(tmp);
        dfs(rst, s, len, i + 1, cur);
        cur.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> rst;
    vector<string> cur;
    dfs(rst, s, s.size(), 0, cur);
    return rst;
  }
};