#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> cache;
    for (char c : s) {
      cache[c]++;
    }
    for (char c : t) {
      cache[c]--;
      if (cache[c] == -1) {
        return c;
      }
    }
    return ' ';
  }
};