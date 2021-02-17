#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
  unordered_map<string, int> cache;
  int dfs(vector<vector<int>> &triangle, int d, int p) {
    if (d >= triangle.size()) {
      return 0;
    }
    string key = to_string(d) + ',' + to_string(p);
    if (cache.count(key) == 0) {
      cache[key] = triangle[d][p] +
                   min(dfs(triangle, d + 1, p), dfs(triangle, d + 1, p + 1));
    }
    return cache[key];
  }

public:
  int minimumTotal(vector<vector<int>> &triangle) {
    return dfs(triangle, 0, 0);
  }

  // 自顶向上
  int minimumTotal_(vector<vector<int>> &triangle) {
    for (int i = triangle.size() - 1; i > 0; i--) {
      for (int j = 0; j < triangle[i].size() - 1; j++) {
        triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
      }
    }
    return triangle[0][0];
  }
};

int main() {
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << Solution().minimumTotal(triangle) << endl;
  return 0;
}