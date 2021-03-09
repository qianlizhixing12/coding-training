from typing import List


class Solution:

    def exchange(self, nums: List[int]) -> List[int]:
        pos = 0
        for i in range(len(nums)):
            if nums[i] & 1 == 1:
                nums[pos], nums[i] = nums[i], nums[pos]
                pos += 1
        return nums