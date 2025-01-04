#include "leetcode.h"
#include "test.h"

static void llt_twoSum(void) {
  int returnSize = 0;
  int *result = NULL;

  int nums[] = {2, 7, 11, 15};
  int expect[] = {0, 1};
  result = twoSum(nums, sizeof(nums) / sizeof(int), 9, &returnSize);
  TEST_CASE_ARRAY_INT_EQUAL(expect, sizeof(expect) / sizeof(int), result,
                            returnSize);
  free(result);

  int nums1[] = {3, 2, 4};
  int expect1[] = {1, 2};
  result = twoSum(nums1, sizeof(nums1) / sizeof(int), 6, &returnSize);
  TEST_CASE_ARRAY_INT_EQUAL(expect1, sizeof(expect1) / sizeof(int), result,
                            returnSize);
  free(result);

  int nums2[] = {3, 3};
  int expect2[] = {0, 1};
  result = twoSum(nums2, sizeof(nums2) / sizeof(int), 6, &returnSize);
  TEST_CASE_ARRAY_INT_EQUAL(expect2, sizeof(expect2) / sizeof(int), result,
                            returnSize);
  free(result);

  int nums3[] = {1, 2};
  result = twoSum(nums3, sizeof(nums3) / sizeof(int), 6, &returnSize);
  TEST_CASE_TRUE(result == NULL);
  TEST_CASE_TRUE(returnSize == 0);
}

static void llt_addTwoNumbers(void) {
  int numsa1[] = {2, 4, 3};
  struct ListNode *numsa1_list = arrToList(numsa1, 3);
  int numsa2[] = {5, 6, 4};
  struct ListNode *numsa2_list = arrToList(numsa2, 3);
  int expecta[] = {7, 0, 8};
  struct ListNode *expecta_list = arrToList(expecta, 3);
  struct ListNode *resulta = addTwoNumbers(numsa1_list, numsa2_list);
  TEST_CASE_LIST_INT_EQUAL(expecta_list, resulta, struct ListNode *);
  freeList(numsa1_list);
  freeList(numsa2_list);
  freeList(expecta_list);
  freeList(resulta);

  int numsb1[] = {0};
  struct ListNode *numsb1_list = arrToList(numsb1, 1);
  int numsb2[] = {0};
  struct ListNode *numsb2_list = arrToList(numsb2, 1);
  int expectb[] = {0};
  struct ListNode *expectb_list = arrToList(expectb, 1);
  struct ListNode *resultb = addTwoNumbers(numsb1_list, numsb2_list);
  TEST_CASE_LIST_INT_EQUAL(expectb_list, resultb, struct ListNode *);
  freeList(numsb1_list);
  freeList(numsb2_list);
  freeList(expectb_list);
  freeList(resultb);

  int numsc1[] = {9, 9, 9, 9, 9, 9, 9};
  struct ListNode *numsc1_list = arrToList(numsc1, 7);
  int numsc2[] = {9, 9, 9, 9};
  struct ListNode *numsc2_list = arrToList(numsc2, 4);
  int expectc[] = {8, 9, 9, 9, 0, 0, 0, 1};
  struct ListNode *expectc_list = arrToList(expectc, 8);
  struct ListNode *resultc = addTwoNumbers(numsc1_list, numsc2_list);
  TEST_CASE_LIST_INT_EQUAL(expectc_list, resultc, struct ListNode *);
  freeList(numsc1_list);
  freeList(numsc2_list);
  freeList(expectc_list);
  freeList(resultc);
}

void leetcode(void) {
  TEST_CASE_ADD(llt_twoSum);
  TEST_CASE_ADD(llt_addTwoNumbers);
}
