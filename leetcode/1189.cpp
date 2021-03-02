#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> balloon(
        {{'a', 1}, {'b', 1}, {'l', 2}, {'n', 1}, {'o', 2}});
    unordered_map<char, int> word;
    for (char c : text) {
      word[c]++;
    }
    int rst = 0;
    while (true) {
      for (auto &it : balloon) {
        word[it.first] -= it.second;
        if (word[it.first] < 0) {
          return rst;
        }
      }
      rst++;
    }
    return rst;
  }

  int maxNumberOfBalloons_(string text) {
    unordered_map<char, int> balloon(
        {{'a', 1}, {'b', 1}, {'l', 2}, {'n', 1}, {'o', 2}});
    unordered_map<char, int> word;
    for (char c : text) {
      word[c]++;
    }
    int rst = text.size();
    for (auto &it : balloon) {
      rst = min(rst, word[it.first] / it.second);
    }
    return rst;
  }
};