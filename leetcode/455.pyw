from typing import List


class Solution:

    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        count, n = 0, len(g)

        for _, w in enumerate(s):
            if count < n and w >= g[count]:
                count += 1

        return count
