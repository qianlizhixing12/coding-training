#include <string>

using namespace std;

class Solution {
public:
  string replaceSpace(string s) {
    string rst;
    int n = s.size();
    int l = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        rst += s.substr(l, i - l) + "%20";
        l = i + 1;
      }
    }
    rst += s.substr(l);
    return rst;
  }
};