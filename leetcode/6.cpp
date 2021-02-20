#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows < 2 || s.size() < 2) {
      return s;
    }
    vector<string> cache(numRows, "");
    int pos = 0;
    int col = 0;
    while (pos < s.size()) {
      int mod = col % (numRows - 1);
      if (mod == 0) {
        for (int i = 0; i < numRows && pos < s.size(); ++i) {
          cache[i].push_back(s[pos++]);
        }
      } else {
        cache[numRows - 1 - mod].push_back(s[pos++]);
      }
      ++col;
    }
    string ans;
    for_each(cache.begin(), cache.end(), [&](string &val) { ans += val; });
    return ans;
  }
};