#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  // 模仿插入排序，先排序出现在arr2中的，再排序未出现在arr2中的
  vector<int> relativeSortArray_(vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans(arr1.size());
    unordered_map<int, int> cache;
    for (int i = 0; i < arr2.size(); i++) {
      cache[arr2[i]] = i;
    }
    int id = 0;
    for (int i = 0; i < arr1.size(); i++) {
      if (cache.count(arr1[i]) == 0) {
        continue;
      }
      int j = id - 1;
      for (; j >= 0; j--) {
        if (cache[arr1[i]] < cache[ans[j]]) {
          ans[j + 1] = ans[j];
        } else {
          break;
        }
      }
      ans[j + 1] = arr1[i];
      id++;
    }
    int id_ = id;
    for (int i = 0; i < arr1.size(); i++) {
      if (cache.count(arr1[i]) != 0) {
        continue;
      }
      int j = id - 1;
      for (; j >= id_; j--) {
        if (arr1[i] < ans[j]) {
          ans[j + 1] = ans[j];
        } else {
          break;
        }
      }
      ans[j + 1] = arr1[i];
      id++;
    }
    return ans;
  }

  // 自定义排序
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> cache;
    for (int i = 0; i < arr2.size(); i++) {
      cache[arr2[i]] = i;
    }
    sort(arr1.begin(), arr1.end(), [&](int a, int b) {
      if (cache.count(a)) {
        return cache.count(b) ? cache[a] < cache[b] : true;
      } else {
        return cache.count(b) ? false : a < b;
      }
    });
    return arr1;
  }
};

int main() {
  vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
  vector<int> arr2 = {2, 1, 4, 3, 9, 6};
  Solution().relativeSortArray(arr1, arr2);
  return 0;
}