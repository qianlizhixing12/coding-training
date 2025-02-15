/*******************************************************
              Problem 16  Power digit sum
2<<15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2<<1000?
*******************************************************/

// 2的幂各个位数字之和 https://projecteuler.net/problem=16

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int getPowerDigitSum(int num);

int main(int argc, char *argv[]) {
  cout << getPowerDigitSum(5) << endl;
  cout << getPowerDigitSum(15) << endl;
  cout << getPowerDigitSum(1000) << endl;
  return 0;
}

int getPowerDigitSum(int num) {
  // long long int 存储不了2<<1000
  vector<int> data(num + 1, 0);
  data[0] = 1;
  for (int i = 1; i <= num; i++) {
    int pre = 0;
    for (int j = 0; j <= i; j++) {
      data[j] <<= 1;
      data[j] += pre;
      if (data[j] > 9) {
        pre = 1;
        data[j] %= 10;
      } else {
        pre = 0;
      }
    }
  }
  return accumulate(data.begin(), data.end(), 0);
}