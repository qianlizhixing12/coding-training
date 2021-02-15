#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> cache;
    for (int num : nums1) {
      cache.emplace(num);
    }
    vector<int> ans;
    for (int num : nums2) {
      if (cache.count(num) > 0) {
        ans.emplace_back(num);
        cache.erase(num);
      }
    }
    return ans;
  }
};