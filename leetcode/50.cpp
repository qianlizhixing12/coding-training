#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<int, double> cache;
  double myPow_(double x, long n) {
    if (cache.count(n) == 0) {
      double half = myPow_(x, n >> 1);
      if (n & 1) {
        cache[n] = half * half * x;
      } else {
        cache[n] = half * half;
      }
    }
    return cache[n];
  }

public:
  double myPow(double x, long n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }
    if (x == 1) {
      return 1;
    }
    cache[0] = 1;
    cache[1] = x;
    return n >= 0 ? myPow_(x, n) : 1 / myPow_(x, 0 - n);
  }
};

int main() {
  Solution().myPow(2.00000, -2147483648);
  return 0;
}