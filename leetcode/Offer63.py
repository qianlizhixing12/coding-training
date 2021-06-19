from typing import List


class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0

        minv, val = prices[0], 0
        for price in prices:
            if price < minv:
                minv = price
            else:
                val = max(val, price - minv)
        return val
