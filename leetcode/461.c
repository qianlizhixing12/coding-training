int hammingDistance(int x, int y) {
  int n = x ^ y;
  int ans = 0;

  while (n != 0) {
    ++ans;
    n &= n - 1;
  }

  return ans;
}