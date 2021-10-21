from typing import List


class Solution:

    def canJump(self, nums: List[int]) -> bool:
        """贪心，拿最大部去实验
        """
        # right最远距离
        n, right = len(nums), 0
        if n <= 1:
            return True

        for i, num in enumerate(nums):
            if i > right:
                return False
            if num + i >= n:
                return True
            right = max(right, num + i)

        return True
