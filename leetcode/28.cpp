#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle == "") {
      return 0;
    }
    int l = 0;
    int r = haystack.size() - 1;
    int k = needle.size();
    while (l + k - 1 <= r) {
      if (haystack[l] != needle[0]) {
        l++;
      } else if (haystack[r] != needle[k - 1]) {
        r--;
      } else {
        bool ok = true;
        for (int i = 1; i < k; i++) {
          if (needle[i] != haystack[l + i]) {
            l++;
            ok = false;
            break;
          }
        }
        if (ok) {
          return l;
        }
      }
    }
    return -1;
  }
};