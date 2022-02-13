int xorOperation(int n, int start) {
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    ans ^= ((i << 1) + start);
  }

  return ans;
}