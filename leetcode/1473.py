from typing import List


class Solution:

    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        """动态规划
        """
        dp = [[[0] * (target + 1) for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(m + 1):
            for j in range(n + 1):
                dp[i][j][0] = float('inf')

        for i in range(1, m + 1):
            color = houses[i - 1]
            for j in range(1, n + 1):
                for k in range(1, target + 1):
                    if k > i:
                        dp[i][j][k] = float('inf')
                        continue
                    if color != 0:
                        if j == color:
                            dp[i][j][k] = float('inf')
                            for p in range(1, n + 1):
                                if p != j:
                                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][p][k - 1])
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k])
                        else:
                            dp[i][j][k] = float('inf')
                    else:
                        dp[i][j][k] = float('inf')
                        for p in range(1, n + 1):
                            if p != j:
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][p][k - 1])
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]) + cost[i - 1][j - 1]

        res = float('inf')
        for i in range(1, n + 1):
            res = min(res, dp[m][i][target])
        return res if res != float('inf') else -1