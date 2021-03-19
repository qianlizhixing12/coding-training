/*******************************************************
              Problem 7  10001st prime
  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6th prime is 13.What is the 10 001st prime number?
*******************************************************/

#include <iostream>
#include <vector>

using namespace std;

int getPrime(int num);

int main(int argc, char *argv[]) {
  //   cout << getPrime(6) << endl;
  cout << getPrime(10001) << endl;
  return 0;
}

void generatePrime(int start, int end, vector<int> &prime) {
  for (int i = start; i <= end; i = i + 2) {
    bool isPrime = true;
    for (int p : prime) {
      if (i % p == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      prime.emplace_back(i);
    }
  }
}

int getPrime(int num) {
  vector<int> prime = {2};
  int end = num;
  generatePrime(3, end, prime);
  while (prime.size() < num) {
    int start = (end & 1) ? end + 2 : end + 1;
    end = end << 1;
    generatePrime(start, end, prime);
  }
  return prime[num - 1];
}