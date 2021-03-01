#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
    // 合并B
    vector<int> b_(26, 0);
    for (string &s : B) {
      vector<int> cur(26, 0);
      for (char c : s) {
        cur[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        b_[i] = max(b_[i], cur[i]);
      }
    }
    // 逐个比较
    vector<string> ans;
    for (string &s : A) {
      vector<int> cur(26, 0);
      for (char c : s) {
        cur[c - 'a']++;
      }
      bool ok = true;
      for (int i = 0; i < 26; i++) {
        if (cur[i] < b_[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans.emplace_back(s);
      }
    }
    return ans;
  }
};

int main() {
  vector<string> A = {"amazon", "apple", "facebook", "google", "leetcode"};
  vector<string> B = {"e", "o"};
  Solution().wordSubsets(A, B);
  return 0;
}