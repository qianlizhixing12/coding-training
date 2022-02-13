int missingNumber(int* nums, int numsSize) {
  int ans = numsSize;

  for (int i = 0; i < numsSize; ++i) {
    ans ^= (nums[i] ^ i);
  }

  return ans;
}