#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string intToRoman_(int num) {
    vector<int> div = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> sign = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                           "XL", "X",  "IX", "V",  "IV", "I"};
    string ans;
    int pos = 0;
    while (num > 0) {
      for (int i = pos; i < div.size(); i++) {
        if (num / div[i] >= 1) {
          ans += sign[i];
          num -= div[i];
          pos = i;
          break;
        }
      }
    }
    return ans;
  }

  string intToRoman(int num) {
    vector<int> div = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> sign = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                           "XL", "X",  "IX", "V",  "IV", "I"};
    string ans;
    for (int i = 0; i < div.size() && num > 0; i++) {
      while (num / div[i] >= 1) {
        ans += sign[i];
        num -= div[i];
      }
    }
    return ans;
  }
};

int main() {
  Solution().intToRoman(20);
  return 0;
}