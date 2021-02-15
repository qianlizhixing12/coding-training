#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> cache;
    for (int num : arr) {
      cache[num]++;
    }
    unordered_map<int, int> help;
    for (pair<int, int> it : cache) {
      help[it.second]++;
    }
    for (pair<int, int> it : help) {
      if (it.second > 1) {
        return false;
      }
    }
    return true;
  }
};