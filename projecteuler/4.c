/*******************************************************
              Problem 4  Largest palindrome product
  A palindromic number reads the same both ways. The largest
palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*******************************************************/

// 最大回文数 https://projecteuler.net/problem=4

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool isPalindrome(char *number) {
  if (number == NULL) {
    return false;
  }

  int r = strlen(number) - 1;
  int l = 0;

  while (l < r) {
    if (number[l++] != number[r--]) {
      return false;
    }
  }

  return true;
}

int getLargestPalindrome(int bit) {
  int iMax = pow(10, bit) - 1;
  int iMin = pow(10, bit - 1) + 1;
  int result = 0;
  size_t bufLen = sizeof(char) * 2 * bit;
  char *buf = malloc(bufLen);

  for (int i = iMax; i >= iMin; i--) {
    for (int j = i; j >= iMin; j--) {
      int tmp = i * j;
      if (result >= tmp) {
        break;
      }

      memset(buf, 0, bufLen);
      snprintf(buf, bufLen - 1, "%d", tmp);
      if (isPalindrome(buf)) {
        result = tmp;
      }
    }
  }

  free(buf);
  return result;
}
