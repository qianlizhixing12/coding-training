#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> cache;
    for (string s : strs) {
      string sc(s);
      sort(sc.begin(), sc.end());
      if (cache.count(sc) == 0) {
        cache[sc] = vector<string>();
      }
      cache[sc].emplace_back(s);
    }
    vector<vector<string>> ans;
    for (pair<string, vector<string>> it : cache) {
      ans.emplace_back(it.second);
    }
    return ans;
  }
};