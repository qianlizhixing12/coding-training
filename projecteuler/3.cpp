/*******************************************************
              Problem 3  Largest prime factor
  The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*******************************************************/

#include <iostream>
#include <cmath>

using namespace std;

long long getLargestPrime(long long val);
bool dfs(long long &val, long long div);

int main() {
  long long val = 600851475143;
  cout << getLargestPrime(val) << endl;
  return 0;
}

long long getLargestPrime(long long val) {
  if (dfs(val, 2)) {
    return 2;
  }
  long long r = sqrt(val) + 1;
  for (long long i = 3; i <= r; i = i + 2) {
    if (dfs(val, i)) {
      return i;
    }
  }
  return 0;
}

bool dfs(long long &val, long long div) {
  while (val % div == 0) {
    val /= div;
  }
  return val == 1;
}