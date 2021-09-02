#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;

    for (int food : s) {
      if (count == g.size()) {
        break;
      }
      if (food >= g[count]) {
        count++;
      }
    }

    return count;
  }
};