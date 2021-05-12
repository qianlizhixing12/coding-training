from typing import List


class Solution:

    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        dp = [0]
        for num in arr:
            dp.append(dp[-1] ^ num)

        ans = []
        for query in queries:
            ans.append(dp[query[1] + 1] ^ dp[query[0]])

        return ans