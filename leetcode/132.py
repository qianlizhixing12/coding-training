class Solution:

    def minCut(self, s: str) -> int:
        return self.dfs(s) - 1

    def dfs(self, s: str) -> int:
        if s == '':
            return 0
        rst = float('inf')
        for i in range(1, len(s) + 1):
            if self.is_palindrome(s[:i]):
                rst = min(rst, self.dfs(s[i:]))
        return rst + 1

    def is_palindrome(self, s: str):
        return s == s[::-1]


class Solution1:

    def minCut(self, s: str) -> int:
        N = len(s)
        dp = [N] * N
        for i in range(N):
            if self.is_palindrome(s[:i + 1]):
                dp[i] = 0
                continue
            for j in range(i):
                if self.is_palindrome(s[j + 1:i + 1]):
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[N - 1]

    def is_palindrome(self, s: str):
        return s == s[::-1]


if __name__ == "__main__":
    print(Solution1().minCut("coder"))
    print(Solution1().minCut("aab"))
    print(Solution1().minCut("cbbbcc"))