#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  string removeDuplicates(string S) {
    stack<char> help;
    for (char c : S) {
      if (!help.empty() && help.top() == c) {
        help.pop();
      } else {
        help.push(c);
      }
    }
    int n = help.size();
    string rst(n, ' ');
    while (n > 0) {
      rst[--n] = help.top();
      help.pop();
    }
    return rst;
  }

  string removeDuplicates_(string S) {
    string rst;
    for (char c : S) {
      if (!rst.empty() && rst.back() == c) {
        rst.pop_back();
      } else {
        rst.push_back(c);
      }
    }
    return rst;
  }
};