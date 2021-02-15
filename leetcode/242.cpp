#include <string>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    if (s == "") {
      return true;
    }
    int help[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      help[s[i] - 'a']++;
      help[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (help[i] != 0) {
        return false;
      }
    }
    return true;
  }
};