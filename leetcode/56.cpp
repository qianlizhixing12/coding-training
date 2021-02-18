#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // 有顺序的map
    map<int, int> cache;
    for (int i = 0; i < intervals.size(); i++) {
      if (cache.count(intervals[i][0]) == 0) {
        cache[intervals[i][0]] = i;
      } else {
        if (intervals[cache[intervals[i][0]]][1] < intervals[i][1]) {
          cache[intervals[i][0]] = i;
        }
      }
    }
    vector<vector<int>> ans;
    map<int, int>::iterator cur = cache.begin();
    for (map<int, int>::iterator it = ++cache.begin(); it != cache.end();
         it++) {
      if (intervals[cur->second][0] < intervals[it->second][0] &&
          intervals[cur->second][1] >= intervals[it->second][0]) {
        if (intervals[cur->second][1] < intervals[it->second][1]) {
          intervals[cur->second][1] = intervals[it->second][1];
        }
      } else {
        ans.emplace_back(intervals[cur->second]);
        cur = it;
      }
    }
    ans.emplace_back(intervals[cur->second]);
    return ans;
  }
};

int main() {
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution().merge(intervals);
  return 0;
}