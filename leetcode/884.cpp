#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string, int> cache;
    help(A, cache);
    help(B, cache);
    vector<string> rst;
    for_each(cache.begin(), cache.end(), [&](pair<string, int> it) {
      if (it.second == 1) {
        rst.emplace_back(it.first);
      }
    });
    return rst;
  }

  void help(string &s, unordered_map<string, int> &cache) {
    int n = s.size();
    int l = 0;
    int r = 0;
    for (; r < n; r++) {
      if (s[r] == ' ') {
        if (l != r) {
          cache[s.substr(l, r - l)]++;
        }
        l = r + 1;
      }
    }
    if (l != r) {
      cache[s.substr(l, r - l)]++;
    }
  }
};

int main() {
  string A = "this apple is sweet";
  string B = "this apple is sour";
  Solution().uncommonFromSentences(A, B);
  return 0;
}