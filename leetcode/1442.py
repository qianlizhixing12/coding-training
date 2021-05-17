from typing import List


class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans = 0
        n = len(arr)

        dp = [0] * (n + 1)
        for i in range(n):
            dp[i + 1] = dp[i] ^ arr[i]

        for i in range(n - 1):
            for j in range(i + 1, n):
                for k in range(j, n):
                    if dp[i] == dp[k + 1]:
                        ans += 1
        return ans

    def countTriplets_(self, arr: List[int]) -> int:
        ans = 0
        n = len(arr)

        dp = [0] * (n + 1)
        for i in range(n):
            dp[i + 1] = dp[i] ^ arr[i]

        for i in range(n - 1):
            for k in range(i + 1, n):
                if dp[i] == dp[k + 1]:
                    ans += k - i
        return ans
