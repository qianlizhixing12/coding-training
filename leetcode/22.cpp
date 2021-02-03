#include <vector>
#include <string>

using namespace std;

class Solution {
private:
  void dfs(int left, int right, string cur, vector<string> &result) {
    if (right == 0) {
      result.push_back(cur);
      return;
    }
    if (left == right) {
      dfs(left - 1, right, cur + '(', result);
    } else if (left == 0) {
      dfs(left, right - 1, cur + ')', result);
    } else {
      // left != right && left != 0
      // 即left < right && left > 0
      dfs(left - 1, right, cur + '(', result);
      dfs(left, right - 1, cur + ')', result);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n < 1) {
      return result;
    } else if (n == 1) {
      result.push_back("()");
      return result;
    }
    dfs(n, n, "", result);
    return result;
  }
};