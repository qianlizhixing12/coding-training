#include <string>

using namespace std;

class Solution {
public:
  string replaceSpaces1(string S, int length) {
    int n = S.size() - 1;
    length--;
    while (length >= 0) {
      if (S[length] != ' ') {
        S[n--] = S[length];
      } else {
        S[n--] = '0';
        S[n--] = '2';
        S[n--] = '%';
      }
      length--;
    }
    return S.substr(n);
  }

  string replaceSpaces(string S, int length) {
    string rst;
    for (int i = 0; i < length; i++) {
      if (S[i] != ' ') {
        rst += S[i];
      } else {
        rst += "%20";
      }
    }
    return rst;
  }
};