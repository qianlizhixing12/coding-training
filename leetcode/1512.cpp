#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    if (nums.size() < 2) {
      return 0;
    }
    unordered_map<int, int> cache;
    int count = 0;
    for (int n : nums) {
      count += cache[n]++;
    }
    return count;
  }
};