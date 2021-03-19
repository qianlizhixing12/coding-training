/*******************************************************
              Problem 9  Special Pythagorean triplet
  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2  For example, 32 + 42 = 9 + 16 = 25 = 52.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*******************************************************/

#include <iostream>

using namespace std;

int getSpecialPythagorean(int num);

int main(int argc, char *argv[]) {
  cout << getSpecialPythagorean(1000) << endl;
  return 0;
}

int getSpecialPythagorean(int num) {
  // a <= b < c
  int imax = num >> 1;
  for (int a = 1; a < imax; a++) {
    for (int b = a; b < imax; b++) {
      int c = num - a - b;
      if ((c > b) && (c * c == b * b + a * a)) {
        return a * b * c;
      }
    }
  }
  return 0;
}