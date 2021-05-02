from typing import List
from collections import defaultdict


class Solution:

    def leastBricks(self, wall: List[List[int]]) -> int:
        n = len(wall)
        if sum(wall[0]) == 1:
            return n
        dp = [0 for i in range(1, sum(wall[0]))]
        for i in range(n):
            count = 0
            for j in range(len(wall[i])):
                for k in range(count, count + wall[i][j] - 1):
                    dp[k] += 1
                count += wall[i][j]
        return min(dp)

    def leastBricks_(self, wall: List[List[int]]) -> int:
        dp = defaultdict(int)
        n = len(wall)
        for i in range(n):
            count = 0
            for j in range(len(wall[i]) - 1):
                count += wall[i][j]
                dp[count] += 1
        return n - max(dp.values(), default=0)


Solution().leastBricks_([[1], [1], [1]])