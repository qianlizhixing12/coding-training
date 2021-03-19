/*******************************************************
              Problem 4  Largest palindrome product
  A palindromic number reads the same both ways. The largest
palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*******************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getLargestPalindrome(int bit);
bool isPalindrome(int number);

int main() {
  cout << getLargestPalindrome(3) << endl;
  return 0;
}

int getLargestPalindrome(int bit) {
  int iMax = pow(10, bit) - 1;
  int iMin = pow(10, bit - 1) + 1;
  int result = 0;
  for (int i = iMax; i >= iMin; i--) {
    for (int j = i; j >= iMin; j--) {
      int tmp = i * j;
      if (result >= tmp) {
        break;
      }
      if (isPalindrome(tmp)) {
        result = tmp;
      }
    }
  }
  return result;
}

bool isPalindrome(int number) {
  // sprintf(tmp, "%ld", number)
  string s = to_string(number);
  int r = s.size() - 1;
  int l = 0;
  while (l < r) {
    if (s[l++] != s[r--]) {
      return false;
    }
  }
  return true;
}