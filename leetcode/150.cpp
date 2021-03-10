#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> cache;
    for (string &s : tokens) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        int v1 = cache.top();
        cache.pop();
        int v2 = cache.top();
        cache.pop();
        if (s == "+") {
          v2 += v1;
        } else if (s == "-") {
          v2 -= v1;
        } else if (s == "*") {
          v2 *= v1;
        } else if (s == "/") {
          v2 /= v1;
        }
        cache.push(v2);
      } else {
        cache.push(atoi(s.c_str()));
      }
    }
    return cache.top();
  }
};