#include <iostream>

int getSum(int x, int y, int range);
int getSum_(int x, int y, int range);
int getSum(int x, int range);

int main() {
  std::cout << getSum(3, 5, 1000) << std::endl;
  std::cout << getSum_(3, 5, 1000) << std::endl;
  std::cout << getSum(3, 1000) + getSum(5, 1000) - getSum(15, 1000)
            << std::endl;
  return 0;
}

int getSum(int x, int y, int range) {
  int sum = 0;
  for (int i = 1; (i * x) < range; i++) {
    sum += (i * x);
  }
  for (int i = 1; (i * y) < range; i++) {
    if (i * y % x != 0) {
      sum += (i * y);
    }
  }
  return sum;
}

int getSum_(int x, int y, int range) {
  int sum = 0;
  for (int i = 0; i < range; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}

/*
 * 数学公式 x+x*2+x*3+...+x*n=x(1+2+3+...+n)=x*n*(n+1)/2
 * 3倍数+5倍数-15倍数
 * 时间复杂度O(1)
 */
int getSum(int x, int range) {
  int n = (range - 1) / x;
  return x * n * (n + 1) / 2;
}