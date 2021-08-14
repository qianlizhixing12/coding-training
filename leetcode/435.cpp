#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

bool cmp(const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; }

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    // sort(intervals.begin(), intervals.end(), cmp);
    int n = intervals.size();
    int prev = intervals[0][1];
    int count = 0;
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] < prev) {
        ++count;
      } else {
        prev = intervals[i][1];
      }
    }
    return count;
  }
};