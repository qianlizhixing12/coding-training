#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    vector<vector<string>> ans;
    unordered_set<string> help(wordList.begin(), wordList.end());
    if (help.count(endWord) <= 0) {
      return ans;
    }
    help.erase(endWord);
    vector<vector<string>> b;
    b.emplace_back(vector<string>({beginWord}));
    while (b.size() > 0) {
      vector<vector<string>> tmp;
      vector<string> use;
      for (vector<string> s : b) {
        for (int i = 0; i < s[s.size() - 1].size(); i++) {
          for (int j = 0; j < 26; j++) {
            if ('a' + j == s[s.size() - 1][i]) {
              continue;
            }
            string n = s[s.size() - 1];
            n[i] = 'a' + j;
            if (n == endWord) {
              ans.emplace_back(s);
              ans[ans.size() - 1].emplace_back(n);
            } else if (help.count(n) > 0) {
              tmp.emplace_back(s);
              tmp[tmp.size() - 1].emplace_back(n);
              use.emplace_back(n);
            }
          }
        }
      }
      if (ans.size() > 0) {
        break;
      }
      for (string n : use) {
        help.erase(n);
      }
      b = tmp;
    }
    return ans;
  }
};

int main() {
  // string beginWord = "hit";
  // string endWord = "cog";
  // vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  string beginWord = "red";
  string endWord = "tax";
  vector<string> wordList = {"ted", "tex", "red", "tax",
                             "tad", "den", "rex", "pee"};
  //  [["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
  Solution().findLadders(beginWord, endWord, wordList);
  return 0;
}