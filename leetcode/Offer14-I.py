import collections


class Solution:

    def cuttingRope(self, n: int) -> int:
        '''
        暴力解法 超时
        '''

        def dfs(n: int, cur: int):
            if n == 0:
                self.rst = max(self.rst, cur)
                return

            for i in range(1, n + 1):
                dfs(n - i, cur * i)

        self.rst = 0
        for i in range(1, n):
            dfs(n - i, i)
        return self.rst


class Solution1:

    def cuttingRope(self, n: int) -> int:
        '''
        缓存备忘录
        '''

        def dfs(n: int) -> int:
            if n in self.dp:
                return self.dp[n]
            self.dp[n] = 0
            for i in range(1, n + 1):
                self.dp[n] = max(self.dp[n], i * dfs(n - i))
            return self.dp[n]

        self.dp = {0: 1, n: 0}
        for i in range(1, n):
            self.dp[n] = max(self.dp[n], i * dfs(n - i))
        return self.dp[n]


class Solution2:

    def cuttingRope(self, n: int) -> int:
        '''
        动态规划
        '''
        dp = [1] * (n + 1)
        for i in range(1, n + 1):
            start = 0 if i != n else 1
            for j in range(start, i):
                dp[i] = max(dp[i], (i - j) * dp[j])
        return dp[n]


if __name__ == "__main__":
    # Solution1().cuttingRope(2)
    Solution2().cuttingRope(10)