#include <unordered_set>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> cache;
    for (char c : jewels) {
      cache.emplace(c);
    }
    int count = 0;
    for (char c : stones) {
      if (cache.find(c) != cache.end()) {
        count++;
      }
    }
    return count;
  }
};