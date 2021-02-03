class Solution {
public:
  // n小于等于0直接返回false
  // n & (n-1) 清零最低位的1，2的幂必须只有一个1
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return (n & (n - 1)) == 0;
  }
};