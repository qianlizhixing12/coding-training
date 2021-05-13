class Solution:

    def numWays_(self, steps: int, arrLen: int) -> int:
        """暴力
        """

        def dfs(pos: int, step: int) -> int:
            """在当前位置当前步骤下继续移动

            Args:
                pos : 当前位置
                step : 当前步骤
            """

            if pos == -1 or pos == arrLen:
                return 0

            if step == steps:
                return 1 if pos == 0 else 0

            ans = 0
            for i in (-1, 0, 1):
                ans += dfs(pos + i, step + 1)
            return ans

        return dfs(0, 0)

    def numWays__(self, steps: int, arrLen: int) -> int:
        """缓存备忘录
        """

        def dfs(pos: int, step: int) -> int:
            """在当前位置当前步骤下继续移动

            Args:
                pos : 当前位置
                step : 当前步骤
            """
            if pos == -1 or pos == arrLen:
                return 0

            if step == steps:
                return 1 if pos == 0 else 0

            key = (pos, step)
            if key in dp:
                return dp[key]

            ans = 0
            for i in (-1, 0, 1):
                ans += dfs(pos + i, step + 1)
            dp[key] = ans

            return ans

        dp = {}
        return dfs(0, 0) % 1000000007

    def numWays(self, steps: int, arrLen: int) -> int:
        """动态规划
        """
        col = min(arrLen, steps + 1)
        dp = [[0] * col for _ in range(steps + 1)]
        dp[0][0] = 1

        for step in range(1, steps + 1):
            for pos in range(col):
                dp[step][pos] += dp[step - 1][pos]
                if pos > 0:
                    dp[step][pos] += dp[step - 1][pos - 1]
                if pos + 1 < col:
                    dp[step][pos] += dp[step - 1][pos + 1]

        return dp[steps][0] % 1000000007
