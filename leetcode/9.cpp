#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome_(int x) {
    if (x < 0) {
      return false;
    }
    if (x < 10) {
      return true;
    }
    if (x % 10 == 0) {
      return false;
    }
    vector<int> cache;
    while (x != 0) {
      cache.emplace_back(x % 10);
      x /= 10;
    }
    for (int i = 0, j = cache.size() - 1; i < j; i++, j--) {
      if (cache[i] != cache[j]) {
        return false;
      }
    }
    return true;
  }

  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x < 10) {
      return true;
    }
    if (x % 10 == 0) {
      return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
      revertedNumber = revertedNumber * 10 + x % 10;
      x /= 10;
    }
    return revertedNumber == x || x == revertedNumber / 10;
  }
};