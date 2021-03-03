#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isUnique(string astr) {
    unordered_set<char> cache;
    for (char c : astr) {
      if (cache.find(c) != cache.end()) {
        return false;
      }
      cache.emplace(c);
    }
    return true;
  }

  bool isUnique1(string astr) {
    sort(astr.begin(), astr.end());
    int n = astr.size();
    for (int i = 1; i < n; ++i) {
      if (astr[i] == astr[i - 1]) {
        return false;
      }
    }
    return true;
  }

  bool isUnique2(string astr) {
    int mask = 0;
    for (char c : astr) {
      int val = 1 << (c - 'a');
      if ((val & mask) != 0) {
        return false;
      }
      mask |= val;
    }
    return true;
  }
};