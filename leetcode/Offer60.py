from typing import List
from collections import defaultdict


class Solution:

    def dicesProbability_(self, n: int) -> List[float]:

        def helper(n):
            nonlocal count
            if n in count:
                return

            m1, m2, count[n] = n >> 1, n >> 1 if (n & 1) == 0 else (n >> 1) + 1, defaultdict(int)
            helper(m1)
            helper(m2)

            for n1, v1 in count[m1].items():
                for n2, v2 in count[m2].items():
                    count[n][n1 + n2] += v1 * v2

        count = {1: {i: 1 for i in range(1, 7)}}
        helper(n)
        total, nums = sum(count[n].values()), sorted(count[n].keys())
        return [count[n][num] / total for num in nums]

    def dicesProbability(self, n: int) -> List[float]:
        """动态规划
        """
        dp = {i: 1 for i in range(1, 7)}
        for i in range(2, n + 1):
            cur = defaultdict(int)
            for n, v in dp.items():
                for j in range(1, 7):
                    cur[n + j] += v
            dp = cur

        total, nums = sum(dp.values()), sorted(dp.keys())
        return [dp[num] / total for num in nums]
