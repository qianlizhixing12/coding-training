#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  vector<string> book{"_",   "!@#", "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> result;
  void bfs(string &digits, string cur, int level) {
    if (level >= digits.size()) {
      if (cur != "") {
        result.push_back(cur);
      }
      return;
    }
    int key = digits[level] - '0';
    for (char ch : book[key]) {
      bfs(digits, cur + ch, level + 1);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    bfs(digits, "", 0);
    return result;
  }
};

int main() {
  Solution solution;
  vector<string> result = solution.letterCombinations("23");
  for_each(result.begin(), result.end(),
           [](string value) { cout << value << endl; });
  return 0;
}