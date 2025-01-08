// 范围内3与5倍数的和 https://projecteuler.net/problem=1

#include <stdio.h>
#include <stdlib.h>

/*
 * 数学公式 x+x*2+x*3+...+x*n=x(1+2+3+...+n)=x*n*(n+1)/2
 * 3倍数+5倍数-15倍数
 * 时间复杂度O(1)
 */
int getMultiplesSum(int x, int y, int range) {
  int nx = (range - 1) / x;
  int sum1 = x * nx * (nx + 1) / 2;
  int ny = (range - 1) / y;
  int sum2 = y * ny * (ny + 1) / 2;
  int nxy = (range - 1) / (x * y);
  int sum3 = x * y * nxy * (nxy + 1) / 2;
  return sum1 + sum2 - sum3;
}