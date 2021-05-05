from typing import List
from collections import Counter


class Solution:

    def deleteAndEarn(self, nums: List[int]) -> int:
        """暴力解法
        """

        def dfs(count, nums):
            ans = 0
            for num in nums:
                item = set(nums)
                item.remove(num)
                if num - 1 in item:
                    item.remove(num - 1)
                if num + 1 in item:
                    item.remove(num + 1)
                ans = max(ans, dfs(count, item) + num * count[num])
            return ans

        count = Counter(nums)
        item = set(nums)

        return dfs(count, item)

    def deleteAndEarn_(self, nums: List[int]) -> int:
        """转换思路
        """
        count = Counter(nums)
        max_ = max(nums)
        dp = [[0, 0] for _ in range(max_ + 1)]

        for i in range(1, max_ + 1):
            # 数字i不选
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
            # 数字i选择
            dp[i][1] = dp[i - 1][0] + i * (count[i] if i in count else 0)
        return max(dp[max_])


Solution().deleteAndEarn_([3, 4, 2])
