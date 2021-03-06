#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &T) {
    stack<int> s;
    vector<int> rst(T.size());
    for (int i = T.size() - 1; i >= 0; i--) {
      while (!s.empty() && T[s.top()] <= T[i]) {
        s.pop();
      }
      rst[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }
    return rst;
  }
};