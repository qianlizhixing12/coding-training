from typing import List


class Solution:

    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        cache = [0]

        for num in arr:
            cache.append(cache[-1] ^ num)

        ans = []

        for query in queries:
            ans.append(cache[query[0]] ^ cache[query[1] + 1])

        return ans


Solution().xorQueries([1, 3, 4, 8], [[0, 1], [1, 2], [0, 3], [3, 3]])
