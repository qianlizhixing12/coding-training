#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  vector<int> ans;
  vector<bool> visit;

  bool rec(int pos) {
    if (pos == ans.size()) {
      return true;
    } else if (ans[pos] != 0) {
      return rec(pos + 1);
    }

    for (int n = visit.size() - 1; n > 0; n--) {
      if (visit[n]) {
        continue;
      }
      if (n == 1) {
        ans[pos] = n;
        visit[n] = true;
        if (rec(pos + 1)) {
          return true;
        }
        ans[pos] = 0;
        visit[n] = false;
      } else {
        if (pos + n >= ans.size()) {
          continue;
        }
        if (ans[pos + n] != 0) {
          continue;
        }
        ans[pos] = n;
        ans[pos + n] = n;
        visit[n] = true;
        if (rec(pos + 1)) {
          return true;
        }
        ans[pos] = 0;
        ans[pos + n] = 0;
        visit[n] = false;
      }
    }

    return false;
  }

public:
  vector<int> constructDistancedSequence(int n) {
    ans.resize(2 * n - 1, 0);
    visit.resize(n + 1, false);
    rec(0);
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> result = s.constructDistancedSequence(5);
  for_each(result.begin(), result.end(),
           [](int value) { cout << value << ' '; });
  cout << endl;
  return 0;
}