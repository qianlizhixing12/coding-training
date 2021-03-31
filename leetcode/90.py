from typing import List
import collections
import copy


class Solution:

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = [[]]
        help = collections.defaultdict(int)
        for i in range(len(nums)):
            j = help[nums[i]]
            n = len(ans)
            while j < n:
                cur = copy.deepcopy(ans[j])
                cur.append(nums[i])
                ans.append(cur)
                j += 1
            help[nums[i]] = j
        return ans


if __name__ == "__main__":
    print(Solution().subsetsWithDup([1, 2, 2]))
