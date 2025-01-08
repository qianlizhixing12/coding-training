/*******************************************************
              Problem 3  Largest prime factor
  The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*******************************************************/

// 最大质因子 https://projecteuler.net/problem=3

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isFactor(long long int *val, long long int div) {
  while (*val % div == 0) {
    *val /= div;
  }
  return *val == 1;
}

long long int getLargestPrimeFactor(long long int val) {
  if (isFactor(&val, 2)) {
    return 2;
  }
  long long int r = sqrt(val) + 1;
  for (long long int i = 3; i <= r; i = i + 2) {
    if (isFactor(&val, i)) {
      return i;
    }
  }
  return 0;
}
