import math


class Solution:

    def numSquares(self, n: int) -> int:
        nums = [i * i for i in range(1, int(math.sqrt(n)) + 1)]
        dp = [float("inf")] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for num in nums:
                if num > i:
                    break
                dp[i] = min(dp[i], dp[i - num] + 1)
        return dp[n]
