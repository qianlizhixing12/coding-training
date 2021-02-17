#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> cache;
    for (string &s : cpdomains) {
      int start = s.find(' ');
      int count = atoi(s.substr(0, start).c_str());
      while (start < s.size()) {
        cache[s.substr(start + 1)] += count;
        start = s.find('.', start + 1);
      }
    }
    vector<string> ans;
    for (unordered_map<string, int>::iterator it = cache.begin();
         it != cache.end(); it++) {
      ans.emplace_back(to_string(it->second) + " " + it->first);
    }
    return ans;
  }
};

int main() {
  vector<string> cpdomains = {"9001 discuss.leetcode.com"};
  Solution().subdomainVisits(cpdomains);
  return 0;
}