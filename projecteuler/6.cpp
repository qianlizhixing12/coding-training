/*******************************************************
              Problem 6  Sum square difference
  The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the
first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first
one hundred natural numbers and the square of the sum.
*******************************************************/

// 和平方与平方和值之差 https://projecteuler.net/problem=6

#include <iostream>

using namespace std;

int getSumSquareDifference(int num);

int main() {
  cout << getSumSquareDifference(100) << endl;
  return 0;
}

int getSumSquareDifference(int num) {
  int result = 0;
  for (int i = 1; i < num; i++) {
    for (int j = i + 1; j <= num; j++) {
      result += i * j;
    }
  }
  return result * 2;
}