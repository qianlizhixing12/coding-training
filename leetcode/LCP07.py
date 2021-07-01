from typing import List
from collections import defaultdict


class Solution:

    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        """深度优先遍历
        """

        def dfs(i, step):
            nonlocal paths
            if step == k:
                if i == n - 1:
                    paths += 1
                return

            for j in routes[i]:
                dfs(j, step + 1)

        routes, paths = defaultdict(list), 0
        for route in relation:
            routes[route[0]].append(route[1])
        dfs(0, 0)
        return paths

    def numWays_(self, n: int, relation: List[List[int]], k: int) -> int:
        """动态规划
        """
        dp = [[0] * n for _ in range(k + 1)]
        dp[0][0] = 1

        for i in range(k):
            for route in relation:
                dp[i + 1][route[1]] += dp[i][route[0]]

        return dp[-1][-1]
