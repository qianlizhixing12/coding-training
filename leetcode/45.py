from typing import List


class Solution:

    def jump(self, nums: List[int]) -> int:
        """贪心算法
        """
        n, pos, right, skip = len(nums), 0, 0, 0
        for i in range(n - 1):
            right = max(right, i + nums[i])
            if i == pos:
                pos = right
                skip += 1
        return skip

    def jump1(self, nums: List[int]) -> int:
        """动态规划
        """
        n = len(nums)
        dp = [float('inf')] * n
        dp[0] = 0
        for i in range(n - 1):
            for j in range(i, i + nums[i] + 1):
                if j >= n:
                    break
                dp[j] = min(dp[j], dp[i] + 1)
        return dp[-1]
