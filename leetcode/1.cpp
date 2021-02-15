#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> cache;
    for (int i = 0; i < nums.size(); i++) {
      if (cache.count(target - nums[i]) > 0) {
        return vector<int>({cache[target - nums[i]], i});
      }
      cache[nums[i]] = i;
    }
    return vector<int>();
  }
};