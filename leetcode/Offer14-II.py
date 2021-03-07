class Solution:

    def cuttingRope(self, n: int) -> int:
        '''
        动态规划
        '''
        dp = [1] * (n + 1)
        for i in range(1, n + 1):
            start = 0 if i != n else 1
            for j in range(start, i):
                dp[i] = max(dp[i], (i - j) * dp[j])
        return dp[n] % 1000000007