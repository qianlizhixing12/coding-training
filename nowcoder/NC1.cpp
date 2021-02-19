#include <string>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 计算两个数之和
   * @param s string字符串 表示第一个整数
   * @param t string字符串 表示第二个整数
   * @return string字符串
   */
  string solve(string s, string t) {
    // write code here
    if (s == "" || t == "") {
      return s == "" ? t : s;
    }
    // 补长度，使两者相等
    if (s.size() < t.size()) {
      s = string(t.size() - s.size(), '0') + s;
    } else if (s.size() > t.size()) {
      t = string(s.size() - t.size(), '0') + t;
    }
    string ans(s.size(), ' ');
    int sign = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      int val = s[i] - '0' + t[i] - '0' + sign;
      sign = val > 9 ? 1 : 0;
      ans[i] = (val % 10) + '0';
    }
    if (sign == 1) {
      ans = '1' + ans;
    }
    return ans;
  }
};

int main() {
  string s = "733064366";
  string t = "459309139";
  Solution().solve(s, t);
  return 0;
}