#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
  bool dfs(unordered_set<int> &cache, vector<int> &arr, int start) {
    if (start < 0 || start >= arr.size()) {
      return false;
    }
    // start为0
    if (arr[start] == 0) {
      return true;
    }
    if (cache.find(start) != cache.end()) {
      return false;
    }
    cache.insert(start);
    return dfs(cache, arr, start - arr[start]) ||
           dfs(cache, arr, start + arr[start]);
  }

public:
  bool canReach(vector<int> &arr, int start) {
    unordered_set<int> cache;
    return dfs(cache, arr, start);
  }
};

int main() {
  vector<int> arr({4, 2, 3, 0, 3, 1, 2});
  int start = 5;
  cout << Solution().canReach(arr, start) << endl;
  return 0;
}