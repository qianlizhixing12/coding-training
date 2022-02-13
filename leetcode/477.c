int totalHammingDistance(int* nums, int numsSize) {
  int ans = 0;

  for (int i = 0; i < 32; ++i) {
    int count = 0;

    for (int j = 0; j < numsSize; ++j) {
      count += (nums[j] >> i) & 1;
    }

    ans += count * (numsSize - count);
  }

  return ans;
}