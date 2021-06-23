class Solution:

    def translateNum_(self, num: int) -> int:
        s = str(num)
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i, c in enumerate(s):
            dp[i + 1] += dp[i]
            if i > 0 and 9 < int(s[i - 1:i + 1]) < 26:
                dp[i + 1] += dp[i - 1]
        return dp[-1]

    def translateNum(self, num: int) -> int:
        s, a, b = str(num), 1, 1
        for i, ch in enumerate(s):
            a, b = b, a + b if i > 0 and 9 < int(s[i - 1:i + 1]) < 26 else b
        return b