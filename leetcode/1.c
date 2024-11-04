#include "leetcode.h"
#include "uthash.h"

typedef struct {
  int val;
  int idx;
  UT_hash_handle hh;
} HashCache;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  HashCache *cache = NULL;

  for (int i = 0; i < numsSize; ++i) {
    HashCache *pair = NULL;
    int value = target - nums[i];
    HASH_FIND_INT(cache, &value, pair);
    if (pair != NULL) {
      *returnSize = 2;
      int *result = malloc(sizeof(int) * 2);
      result[0] = pair->idx;
      result[1] = i;
      HASH_CLEAR(hh, cache);
      return result;
    }

    HashCache *node = malloc(sizeof(HashCache));
    node->val = nums[i];
    node->idx = i;
    HASH_ADD_INT(cache, val, node);
  }

  HASH_CLEAR(hh, cache);
  *returnSize = 0;
  return NULL;
}
