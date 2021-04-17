from typing import List


class Solution:

    def containsDuplicate(self, nums: List[int]) -> bool:
        # return len(set(nums)) != len(nums)
        help = set()
        for num in nums:
            if num in help:
                return True
            help.add(num)
        return False