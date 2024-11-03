#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/* [projecteuler](https://projecteuler.net/) */
// 1 范围内3与5倍数的和 https://projecteuler.net/problem=1
// int getSum_(int x, int y, int range);
// - [2 范围内斐波那契数列的和](https://projecteuler.net/problem=2)
// 3 最大质因子 https://projecteuler.net/problem=3
// long long getLargestPrime(long long val);
// - [4 最大回文数](https://projecteuler.net/problem=4)
// - [5 最小合数](https://projecteuler.net/problem=5)
// - [6 和平方与平方和值之差](https://projecteuler.net/problem=6)
// - [7 第10001个质数](https://projecteuler.net/problem=7)
// - [8 相邻数字最大乘积](https://projecteuler.net/problem=8)
// - [9 毕达哥拉斯三元数组](https://projecteuler.net/problem=9)
// - [10 范围内质数和](https://projecteuler.net/problem=10)
// - [11 相邻数字最大乘积](https://projecteuler.net/problem=11)
// - [12 质因子个数](https://projecteuler.net/problem=12)
// - [13 数字和前10位](https://projecteuler.net/problem=13)
// - [14 最长Collatz序列](https://projecteuler.net/problem=14)
// - [15 到达网格的路径数](https://projecteuler.net/problem=15)
// - [16 2的幂各个位数字之和](https://projecteuler.net/problem=16)
// - [17 数字英文写法包含的字母](https://projecteuler.net/problem=17)
// - [18 三角路径最大值](https://projecteuler.net/problem=18)

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }

void llt_add(void) {
  TEST_CASE_TRUE(add(2, 3) == 5);
  TEST_CASE_TRUE(add(4, 5) == 5);
}

void llt_sub(void) {
  TEST_CASE_TRUE(sub(6, 3) == 3);
  TEST_CASE_TRUE(sub(4, 5) == 5);
  TEST_CASE_TRUE(sub(6, 5) == 1);
}

void projecteuler() {
  TEST_UNIT_ADD(llt_add);
  TEST_UNIT_ADD(llt_sub);

  TEST_UNIT_RUN();
}

int main(int argc, char **argv) {
  projecteuler();

  return 0;
}