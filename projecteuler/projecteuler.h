#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int getMultiplesSum(int x, int y, int range);
extern long long int getEvenFibonacciSum(long long int range);
extern long long int getLargestPrimeFactor(long long int val);
extern int getLargestPalindrome(int bit);
extern int getSmallestMultiple(int num);

#ifdef __cplusplus
}
#endif
#endif
