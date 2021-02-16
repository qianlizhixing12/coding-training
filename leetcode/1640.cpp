#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    unordered_map<int, vector<vector<int>>::iterator> cache;
    for (vector<vector<int>>::iterator it = pieces.begin(); it != pieces.end();
         it++) {
      if (it->size() > 0) {
        int val = (*it)[0];
        cache[val] = it;
      }
    }
    int i = 0;
    while (i < arr.size()) {
      if (cache.count(arr[i]) == 0) {
        break;
      }
      vector<vector<int>>::iterator it = cache[arr[i]];
      for (vector<int>::iterator node = it->begin(); node != it->end();
           node++) {
        if (*node != arr[i]) {
          goto over;
        }
        i++;
      }
    }
  over:;
    return i == arr.size();
  }

  // 映射数组索引
  bool canFormArray_(vector<int> &arr, vector<vector<int>> &pieces) {
    unordered_map<int, int> cache;
    for (int i = 0; i < pieces.size(); i++) {
      cache[pieces[i][0]] = i;
    }
    for (int i = 0; i < arr.size();) {
      if (cache.count(arr[i]) == 0) {
        return false;
      }
      int id = cache[arr[i]];
      for (int j = 0; j < pieces[id].size();) {
        if (pieces[id][j++] != arr[i++]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  vector<int> arr = {85};
  vector<vector<int>> pieces = {{85}};
  Solution().canFormArray(arr, pieces);
  return 0;
}