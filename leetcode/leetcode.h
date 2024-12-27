#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode {
  int val;
  struct ListNode *next;
};

extern int *twoSum(int *nums, int numsSize, int target, int *returnSize);

extern struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

#ifdef __cplusplus
}
#endif
#endif
