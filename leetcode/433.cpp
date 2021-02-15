#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {

public:
  int minMutation(string start, string end, vector<string> &bank) {
    unordered_set<string> help(bank.begin(), bank.end());
    if (help.count(end) == 0) {
      return -1;
    }
    unordered_set<string> s = {start};
    unordered_set<string> e = {end};
    unordered_set<string> *ps = &s;
    unordered_set<string> *pe = &e;
    int step = 0;
    while (ps->size() > 0 && pe->size() > 0) {
      step++;
      unordered_set<string> tmp;
      for (string s1 : *ps) {
        for (int i = 0; i < s1.size(); i++) {
          for (char c : "ACGT") {
            if (c == s1[i]) {
              continue;
            }
            string ns = s1;
            ns[i] = c;
            if (pe->count(ns) > 0) {
              return step;
            }
            if (help.count(ns) > 0) {
              tmp.insert(ns);
              help.erase(ns);
            }
          }
        }
      }
      if (tmp.size() > pe->size()) {
        *ps = *pe;
        *pe = tmp;
      } else {
        *ps = tmp;
      }
    }
    return -1;
  }
};