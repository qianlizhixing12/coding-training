#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> count;
    for (auto &word : words) {
      ++count[word];
    }

    vector<string> ans;
    for (auto &item : count) {
      ans.emplace_back(item.first);
    }

    sort(ans.begin(), ans.end(), [&](const string &s1, const string &s2) {
      return count[s1] == count[s2] ? s1 < s2 : count[s1] > count[s2];
    });
    ans.erase(ans.begin() + k, ans.end());

    return ans;
  }
};