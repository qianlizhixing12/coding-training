from typing import List


class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
    """双指针
    """
        left, right = 0, len(nums) - 1
        while left < right:
            tmp = nums[left] + nums[right]
            if tmp == target:
                return [nums[left], nums[right]]
            if tmp < target:
                left += 1
            else:
                right -= 1
