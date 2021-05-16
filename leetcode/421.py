from typing import List


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        trie = {}
        for num in nums:
            root = trie
            for i in range(31, -1, -1):
                code = (num >> i) & 1
                root.setdefault(code, {})
                root = root[code]

        ans = float("-inf")
        for num in nums:
            root = trie
            cur = 0
            for i in range(31, -1, -1):
                code = (num >> i) & 1
                if code ^ 1 in root:
                    cur += (1 << i)
                    root = root[code ^ 1]
                else:
                    root = root[code]
            ans = max(ans, cur)

        return ans
