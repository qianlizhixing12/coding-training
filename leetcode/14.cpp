#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  string longestCommonPrefix_(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    int len = min_element(strs.begin(), strs.end(), [](string &s1, string &s2) {
                return s1.size() <= s2.size();
              })->size();
    for (int i = 0; i < len; ++i) {
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[0][i] != strs[j][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return len > 0 ? strs[0].substr(0, len) : "";
  }

  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    if (strs.size() == 1) {
      return strs[0];
    }
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[j].size() <= i || strs[0][i] != strs[j][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};

int main() {
  vector<string> strs = {"ab", "a"};
  Solution().longestCommonPrefix(strs);
  return 0;
}