/*******************************************************
              Problem 14  Longest Collatz sequence
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains
10 terms. Although it has not been proved yet (Collatz Problem), it is thought
that all starting numbers finish at 1. Which starting number, under one million,
produces the longest chain?
NOTE: Once the chain starts the terms are allowed to
go above one million.
*******************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unordered_map>

using namespace std;

long long int
getCollatzSeqLen(unordered_map<long long int, long long int> &cache,
                 long long int num);

int main(int argc, char *argv[]) {
  // unordered_map<long long int, long long int> cache 释放的好慢
  unordered_map<long long int, long long int> cache = {{1, 1}, {2, 2}};
  long long int result = 2;
  long long int imax = 2;
  for (int i = 3; i < 1000000; i++) {
    int len = getCollatzSeqLen(cache, i);
    if (len >= imax) {
      imax = len;
      result = i;
    }
  }
  cout << result << endl;
  return 0;
}

long long int
getCollatzSeqLen(unordered_map<long long int, long long int> &cache,
                 long long int num) {
  if (cache.find(num) != cache.end()) {
    return cache[num];
  }
  if (num & 1) {
    cache[num] = 1 + getCollatzSeqLen(cache, 3 * num + 1);
  } else {
    cache[num] = 1 + getCollatzSeqLen(cache, num >> 1);
  }
  return cache[num];
}