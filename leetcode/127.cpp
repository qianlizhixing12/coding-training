#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> help(wordList.begin(), wordList.end());
    if (help.count(endWord) <= 0) {
      return 0;
    }
    unordered_set<string> b = {beginWord};
    unordered_set<string> e = {endWord};
    unordered_set<string> *pb = &b;
    unordered_set<string> *pe = &e;
    int step = 1;
    while (pb->size() > 0 && pe->size() > 0) {
      step++;
      unordered_set<string> tmp;
      for (string s : *pb) {
        for (int i = 0; i < s.size(); i++) {
          for (int j = 0; j < 26; j++) {
            if ('a' + j == s[i]) {
              continue;
            }
            string n = s;
            n[i] = 'a' + j;
            if (pe->count(n) > 0) {
              return step;
            }
            if (help.count(n) > 0) {
              tmp.insert(n);
              help.erase(n);
            }
          }
        }
      }
      if (tmp.size() > pe->size()) {
        *pb = *pe;
        *pe = tmp;
      } else {
        *pb = tmp;
      }
    }
    return 0;
  }
};