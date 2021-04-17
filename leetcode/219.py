from typing import List


class Solution:

    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        help = {}
        for i, num in enumerate(nums):
            if num in help and i - help[num] <= k:
                return True
            help[num] = i
        return False