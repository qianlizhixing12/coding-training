/*******************************************************
              Problem 2  Even Fibonacci numbers
  Each new term in the Fibonacci sequence is generated
by adding the previous two terms. By starting with 1 and 2,
the first 10 terms will be:1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose
values do not exceed four million, find the sum of the
even-valued terms.
*******************************************************/

#include <iostream>

using namespace std;

#define MAXNUM 4000000

int main(int argc, char *argv[]) {
  /**
   * 解法二：观察
   * 1   1   2   3   5   8  13 21
   * 奇  奇  偶  奇  奇  偶
   * 数学归纳法证明位置为3，3*1，3*2的值为偶数
   * 比起暴力解法，时间复杂度没有降低 每次跨散步
   */
  long long int sum = 0;
  long long int a = 1;
  long long int b = 1;
  long long int c = a + b;

  while (c < MAXNUM) {
    sum += c;
    a = b + c;
    b = c + a;
    c = a + b;
  }

  cout << sum << endl;

  return 0;
}