#include <stdint.h>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      count++;
      // X & (X-1) 清零最低位的 1
      n &= n - 1;
    }
    return count;
  }
};