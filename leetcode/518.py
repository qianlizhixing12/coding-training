from typing import List


class Solution:

    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for coin in coins:
            if coin > amount:
                continue
            for i in range(amount - coin + 1):
                dp[i + coin] += dp[i]
        return dp[amount]
