from typing import List


class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        """贪心算法
        未持有股票情况下，当天股价小于后一天，买进
        持有股票情况下，当天股价大与等于后有一天，卖出
        """
        if len(prices) <= 1:
            return 0

        earn, price, own = 0, 0, 0
        for i in range(0, len(prices) - 1):
            if own == 0:
                if prices[i] < prices[i + 1]:
                    price = prices[i]
                    own = 1
            else:
                if prices[i] >= prices[i + 1]:
                    earn += prices[i] - price
                    own = 0
        if own == 1 and prices[-1] > price:
            earn += prices[-1] - price
            own = 0
        return earn

    def maxProfit1(self, prices: List[int]) -> int:
        """贪心算法
        未持有股票情况下，当天股价小于后一天，买进
        持有股票情况下，当天股价大与等于后有一天，卖出
        官方答案，也是交易过程改进，相邻两天，只要后一天比前一天价高，就可认为完成一次交易，赚取差价
        """
        earn = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                earn += prices[i] - prices[i - 1]
        return earn