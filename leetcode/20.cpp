#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> help;
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
      if (help.empty()) {
        help.push(*it);
      } else if ((help.top() == '(' && (*it) == ')') ||
                 (help.top() == '{' && (*it) == '}') ||
                 (help.top() == '[' && (*it) == ']')) {
        help.pop();
      } else {
        help.push(*it);
      }
    }
    return help.empty();
  }
};