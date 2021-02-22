#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int bsearch(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] == 1) {
        if (mid == r || nums[mid + 1] == 0) {
          return mid + 1;
        } else {
          l = mid + 1;
        }
      } else {
        r = mid - 1;
      }
    }
    return 0;
  }
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<int> cache;
    for (auto &nums : mat) {
      cache.emplace_back(bsearch(nums));
    }
    // 选择排序
    vector<int> rst;
    int n = cache.size();
    while (k-- > 0) {
      int val = mat[0].size() + 1;
      int id = -1;
      for (int i = 0; i < n; ++i) {
        if (cache[i] != -1 && val > cache[i]) {
          val = cache[i];
          id = i;
        }
      }
      cache[id] = -1;
      rst.emplace_back(id);
    }
    return rst;
  }
};

int main() {
  //   vector<vector<int>> mat = {{1, 1, 0, 0, 0},
  //                              {1, 1, 1, 1, 0},
  //                              {1, 0, 0, 0, 0},
  //                              {1, 1, 0, 0, 0},
  //                              {1, 1, 1, 1, 1}};
  //   int k = 3;
  vector<vector<int>> mat = {
      {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  int k = 1;
  Solution().kWeakestRows(mat, k);
  return 0;
}