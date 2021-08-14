#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int childs = 0;

    for (auto &food : s) {
      if (childs == g.size()) {
        break;
      }

      if (food >= g[childs]) {
        childs++;
      }
    }

    return childs;
  }
};