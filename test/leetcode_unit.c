#include "main.h"
#include "test.h"

static void llt_twoSum(void) {
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  int expect[] = {0, 1};
  int returnSize = 0;
  int *result = twoSum(nums, 4, target, &returnSize);
  TEST_CASE_ARRAY_INT_EQUAL(expect, 2, result, returnSize);
  free(result);

  int nums1[] = {3, 2, 4};
  int target1 = 6;
  int expect1[] = {1, 2};
  int returnSize1 = 0;
  int *result1 = twoSum(nums1, 3, target1, &returnSize1);
  TEST_CASE_ARRAY_INT_EQUAL(expect1, 2, result1, returnSize1);
  free(result1);

  int nums2[] = {3, 3};
  int target2 = 6;
  int expect2[] = {0, 1};
  int returnSize2 = 0;
  int *result2 = twoSum(nums2, 2, target2, &returnSize2);
  TEST_CASE_ARRAY_INT_EQUAL(expect2, 2, result2, returnSize2);
  free(result2);
}

static void llt_addTwoNumbers(void) {}

void leetcode(void) {
  TEST_CASE_ADD(llt_twoSum);
  TEST_CASE_ADD(llt_addTwoNumbers);
}
