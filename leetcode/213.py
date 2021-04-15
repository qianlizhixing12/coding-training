from typing import List


class Solution:

    def rob(self, nums: List[int]) -> int:

        def help(nums: List[int]) -> int:
            if not nums:
                return 0
            dp = [0, 0]
            for num in nums:
                dp[0], dp[1] = max(dp[0], dp[1]), dp[0] + num
            return max(dp)

        if len(nums) == 1:
            return nums[0]
        return max(help(nums[:-1]), help(nums[1:]))
