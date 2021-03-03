#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool CheckPermutation(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
  }

  bool CheckPermutation_(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2) {
      return false;
    }
    unordered_map<char, int> count;
    for (int i = 0; i < n1; i++) {
      count[s1[i]]++;
      count[s2[i]]--;
    }
    for (auto &it : count) {
      if (it.second != 0) {
        return false;
      }
    }
    return true;
  }
};