from typing import List


class Solution:

    def findUnsortedSubarray(self, nums: List[int]) -> int:
        """左右指针
        """
        n = len(nums)
        if n < 2:
            return 0

        max, r = nums[0], -1
        for i in range(n):
            if (max <= nums[i]):
                max = nums[i]
            else:
                r = i

        min, l = nums[n - 1], 0
        for i in range(n - 1, -1, -1):
            if min >= nums[i]:
                min = nums[i]
            else:
                l = i

        return r - l + 1
