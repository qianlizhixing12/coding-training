class Solution:

    def nthUglyNumber(self, n: int) -> int:
        dp, p2, p3, p5 = [1], 0, 0, 0
        for i in range(2, n + 1):
            v2, v3, v5 = 2 * dp[p2], 3 * dp[p3], 5 * dp[p5]
            v = min(v2, v3, v5)
            dp.append(v)
            if v == v2:
                p2 += 1
            if v == v3:
                p3 += 1
            if v == v5:
                p5 += 1
        return dp[-1]
