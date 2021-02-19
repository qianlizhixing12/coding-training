#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    unordered_map<char, int> cache;
    unordered_map<char, int> use;
    for (char &c : chars) {
      cache[c]++;
    }
    int count = 0;
    for (string &s : words) {
      bool ok = true;
      use.clear();
      for (char &c : s) {
        if (cache.count(c) == 0) {
          ok = false;
          break;
        }
        use[c]++;
      }
      for (unordered_map<char, int>::iterator it = use.begin(); it != use.end();
           it++) {
        if (it->second > cache[it->first]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        count += s.size();
      }
    }
    return count;
  }
};

int main() {
  vector<string> words = {
      "dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfp"
      "iwyfhzyonmuabtlwin",
      "ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb",
      "ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl",
      "boygirdlggnh",
      "xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx",
      "nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepis"
      "usvsidhqmszbrnynkyop",
      "hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx",
      "juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr",
      "lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo",
      "oxgaskztzroxuntiwlfyufddl",
      "tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrk"
      "xp",
      "qnagrpfzlyrouolqquytwnwnsqnmuzphne",
      "eeilfdaookieawrrbvtnqfzcricvhpiv",
      "sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz",
      "yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue",
      "hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpef"
      "hxekgpuvgiyeudhncv",
      "cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo",
      "teyygdmmyadppuopvqdodaczob",
      "qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs",
      "qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"};
  string chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
  cout << Solution().countCharacters(words, chars) << endl;
  return 0;
}