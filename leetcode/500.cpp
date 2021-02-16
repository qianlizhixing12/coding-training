#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> findWords(vector<string> &words) {
    unordered_map<char, int> cache;
    for (char c : "qwertyuiop") {
      cache[c] = 1;
    }
    for (char c : "asdfghjkl") {
      cache[c] = 2;
    }
    for (char c : "zxcvbnm") {
      cache[c] = 3;
    }
    vector<string> ans;
    for (string &word : words) {
      int first = cache[tolower(word[0])];
      for (int i = 1; i < word.size(); i++) {
        if (first != cache[tolower(word[i])]) {
          goto over;
        }
      }
      ans.emplace_back(word);
    over:;
    }
    return ans;
  }
};