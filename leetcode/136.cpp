#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    // 记录出现1次的数字
    unordered_set<int> cache1;
    // 数字-->次数
    unordered_map<int, int> cache2;
    for (int num : nums) {
      cache2[num]++;
      if (cache2[num] == 1) {
        cache1.emplace(num);
      } else {
        cache1.erase(num);
      }
    }
    return *cache1.begin();
  }

  int singleNumberBit(vector<int> &nums) {
    int result = 0;
    for (int num : nums) {
      result ^= num;
    }
    return result;
  }
};