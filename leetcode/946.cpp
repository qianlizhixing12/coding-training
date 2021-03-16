#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> help;
    int i = 0;
    for (auto num : pushed) {
      help.push(num);
      while (not help.empty() && help.top() == popped[i]) {
        help.pop();
        i++;
      }
    }
    return help.empty();
  }
};