from typing import List
from collections import defaultdict


class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        """暴力解法
        """

        def dfs(n, cur, pos):
            if cur >= n:
                return 0

            # 当前位置不连接
            ans = dfs(n, cur + 1, pos)
            # 二分查找?
            for index in count[nums2[cur]]:
                if index <= pos:
                    continue
                ans = max(ans, 1 + dfs(n, cur + 1, index))
            return ans

        count = defaultdict(list)
        for i, num in enumerate(nums1):
            count[num].append(i)

        return dfs(len(nums2), 0, -1)

    def maxUncrossedLines_(self, nums1: List[int], nums2: List[int]) -> int:
        """缓存备忘录
        """

        def dfs(n, cur, pos):
            key = (cur, pos)
            if key in cache:
                return cache[key]
            if cur >= n:
                return 0

            # 当前位置不连接
            ans = dfs(n, cur + 1, pos)
            # 二分查找?
            for index in count[nums2[cur]]:
                if index <= pos:
                    continue
                ans = max(ans, 1 + dfs(n, cur + 1, index))
            cache[key] = ans
            return ans

        count = defaultdict(list)
        for i, num in enumerate(nums1):
            count[num].append(i)
        cache = {}

        return dfs(len(nums2), 0, -1)

    def maxUncrossedLines__(self, nums1: List[int], nums2: List[int]) -> int:
        """动态规划
        """
        m, n = len(nums1), len(nums2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i, num1 in enumerate(nums1):
            for j, num2 in enumerate(nums2):
                if num1 == num2:
                    dp[i+1][j+1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = max(dp[i][j+1], dp[i+1][j])

        return dp[m][n]
