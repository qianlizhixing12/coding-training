from typing import List


class Solution:

    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        """
        S(正) - S(负) = target
        S(正) + S(负) + S(正) - S(负) = S(正) + S(负) + target 
        2S(正) = target + S(总)
        S(正) = (S(总) + targer) / 2
        转换为背包问题，跳一组数(运算时为负数)，和为(S(总) - targer) / 2
        """
        total = sum(nums)
        if total < target or (total + target) % 2 == 1:
            return 0
        target = (total + target) // 2
        dp = [0] * (target + 1)
        dp[0] = 1
        for num in nums:
            for i in range(target, num - 1, -1):
                dp[i] += dp[i - num]
        return dp[target]


Solution().findTargetSumWays([1000], -1000)
