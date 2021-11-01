from typing import List


class Solution:

    def checkPossibility(self, nums: List[int]) -> bool:
        c, n = 0, len(nums)
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                c += 1
                if c > 1:
                    return False
                if i > 0 and nums[i + 1] < nums[i - 1]:
                    nums[i + 1] = nums[i]
        return True
