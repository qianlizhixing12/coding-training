from typing import List


class Solution:

    def isStraight_(self, nums: List[int]) -> bool:
        nums, diff, fix = sorted(nums), 0, 0
        for i in range(1, 5):
            if nums[i - 1] == 0:
                fix += 1
            elif nums[i] == nums[i - 1]:
                return False
            else:
                diff += nums[i] - nums[i - 1] - 1
        return diff <= fix

    def isStraight(self, nums: List[int]) -> bool:
        maxv, minv, helper = 1, 14, set()
        for num in nums:
            if num == 0:
                continue
            if num in helper:
                return False
            minv = min(minv, num)
            maxv = max(maxv, num)
            helper.add(num)
        return maxv - minv <= 4
