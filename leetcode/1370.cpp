#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  string sortString_(string s) {
    if (s == "") {
      return s;
    }
    string use(s.size(), '0');
    string ans(s.size(), ' ');
    sort(s.begin(), s.end());
    int pos = 0;
    bool desc = true;
    while (pos < s.size()) {
      char c = ' ';
      int i = desc ? 0 : s.size() - 1;
      bool ok = desc ? i < s.size() : i >= 0;
      while (ok) {
        if (use[i] != '1' && s[i] != c) {
          ans[pos++] = s[i];
          use[i] = '1';
          c = s[i];
        }
        desc ? i++ : i--;
        ok = desc ? i < s.size() : i >= 0;
      }
      desc = !desc;
    }
    return ans;
  }

  string sortString(string s) {
    if (s == "") {
      return s;
    }
    vector<int> cache(26, 0);
    for (int i = 0; i < s.size(); i++) {
      cache[s[i] - 'a']++;
    }
    string ans(s.size(), ' ');
    int pos = 0;
    while (pos < s.size()) {
      for (int i = 0; i < 26; i++) {
        if (cache[i] == 0) {
          continue;
        }
        ans[pos++] = i + 'a';
        cache[i]--;
      }
      for (int i = 25; i >= 0; i--) {
        if (cache[i] == 0) {
          continue;
        }
        ans[pos++] = i + 'a';
        cache[i]--;
      }
    }
    return ans;
  }
};

int main() {
  string s = "leetcode";
  Solution().sortString(s);
  return 0;
}