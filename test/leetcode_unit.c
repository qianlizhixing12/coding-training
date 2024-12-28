#include "main.h"
#include "test.h"

struct ListNode *arrToList(int *arr, uint len) {
  if (arr == NULL || len == 0) {
    return NULL;
  }

  struct ListNode *tmp = NULL;

  for (int i = len - 1; i >= 0; --i) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = arr[i];
    node->next = tmp;
    tmp = node;
  }

  return tmp;
}

void freeList(struct ListNode *list) {
  if (list == NULL) {
    return;
  }

  while (list != NULL) {
    struct ListNode *node = list->next;
    free(list);
    list = node;
  }
}

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

static void llt_addTwoNumbers(void) {
  int numsa1[] = {2, 4, 3};
  struct ListNode *numsa1_list = arrToList(numsa1, 3);
  int numsa2[] = {5, 6, 4};
  struct ListNode *numsa2_list = arrToList(numsa2, 3);
  int expecta[] = {7, 0, 8};
  struct ListNode *expecta_list = arrToList(expecta, 3);
  struct ListNode *resulta = addTwoNumbers(numsa1_list, numsa2_list);
  TEST_CASE_LIST_INT_EQUAL(expecta_list, resulta);
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
  TEST_CASE_LIST_INT_EQUAL(expectb_list, resultb);
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
  TEST_CASE_LIST_INT_EQUAL(expectc_list, resultc);
  freeList(numsc1_list);
  freeList(numsc2_list);
  freeList(expectc_list);
  freeList(resultc);
}

void leetcode(void) {
  TEST_CASE_ADD(llt_twoSum);
  TEST_CASE_ADD(llt_addTwoNumbers);
}
