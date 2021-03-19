/*******************************************************
              Problem 10  Summation of primes
  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long int getPrimeSum(long long int num);
bool isPrime(vector<long long int> &primes, long long int num);

int main(int argc, char *argv[]) {
  cout << getPrimeSum(2000000) << endl;
  return 0;
}

long long int getPrimeSum(long long int num) {
  vector<long long int> primes(1, 2);
  for (int i = 3; i <= num; i += 2) {
    if (isPrime(primes, i)) {
      primes.emplace_back(i);
    }
  }
  long long int result = 0;
  for_each(primes.begin(), primes.end(),
           [&result](long long int prime) { result += prime; });
  return result;
}

bool isPrime(vector<long long int> &primes, long long int num) {
  int imax = sqrt(num);
  for (auto p : primes) {
    if (num % p == 0) {
      return false;
    }
    if (p > imax) {
      return true;
    }
  }
  return true;
}