void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  int k = n + m - 1;
  m = m - 1;
  n = n - 1;

  while (n >= 0 && m >= 0) {
    if (nums1[m] > nums2[n]) {
      nums1[k--] = nums1[m--];
    } else {
      nums1[k--] = nums2[n--];
    }
  }

  while (n >= 0) {
    nums1[k--] = nums2[n--];
  }
}