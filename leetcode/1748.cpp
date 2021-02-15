#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int sumOfUnique(vector<int> &nums) {
    unordered_map<int, int> cache;
    for (int n : nums) {
      cache[n]++;
    }
    int sum = 0;
    for (pair<int, int> it : cache) {
      if (it.second == 1) {
        sum += it.first;
      }
    }
    return sum;
  }
};