#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubstring_(string s, int k) {
    if (k < 2) {
      return s.size();
    }
    if (k > s.size()) {
      return 0;
    }
    // 缓冲a到z出现的次数
    int cache[26] = {0};
    for (char c : s) {
      cache[c - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (cache[s[i] - 'a'] < k) {
        // 分段递归获取,类似二分
        return max(longestSubstring_(s.substr(0, i), k),
                   longestSubstring_(s.substr(i + 1, s.size() - i - 1), k));
      }
    };
    return s.size();
  }

  /**
   * @brief longestSubstring_效率太低，多分几段，少几次cache统计
   *
   * @param s
   * @param k
   * @return int
   */
  int longestSubstring(string s, int k) {
    if (k < 2) {
      return s.size();
    }
    if (k > s.size()) {
      return 0;
    }
    // 缓冲a到z出现的次数
    int cache[26] = {0};
    for (char c : s) {
      cache[c - 'a']++;
    }
    // 分段递归获取,类似二分,记录分割位置
    vector<int> split;
    for (int i = 0; i < s.size(); i++) {
      if (cache[s[i] - 'a'] < k) {
        split.push_back(i);
      }
    }
    // 没有分割点，即整段符合条件
    if (split.size() == 0) {
      return s.size();
    }
    // 防止遗漏最右端的情况
    split.push_back(s.size());
    int ans = 0;
    int left = 0;
    for (int i = 0; i < split.size(); i++) {
      if (split[i] - left > ans) {
        ans = max(ans, longestSubstring(s.substr(left, split[i] - left), k));
      }
      left = split[i] + 1;
    };
    return ans;
  }
};

int main() {
  // cout << Solution().longestSubstring("bbaaacbd", 3) << endl;
  cout << Solution().longestSubstring("baaabcb", 3) << endl;
  return 0;
}