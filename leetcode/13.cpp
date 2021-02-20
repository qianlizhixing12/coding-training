#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> cache({{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}});
    int val = 0;
    int prev = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      int cur = cache[s[i]];
      val += (cur >= prev ? cur : -cur);
      prev = cur;
    }
    return val;
  }
};