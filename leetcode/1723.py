from typing import List


class Solution:

    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        """暴力
        """

        def dfs(pos: int, value: int):
            nonlocal ans

            if ans <= value:
                return

            if pos == n:
                ans = value
                return

            for i in range(k):
                dp[i] += jobs[pos]
                dfs(pos + 1, max(value, dp[i]))
                dp[i] -= jobs[pos]

        dp = [0] * k
        n = len(jobs)
        ans = sum(jobs)
        dfs(0, 0)
        return ans
