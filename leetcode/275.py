from typing import List


class Solution:

    def hIndex(self, citations: List[int]) -> int:
        ans, n = 0, len(citations)
        for i, citation in enumerate(citations):
            while ans <= n - i and ans <= citation:
                ans += 1
            if ans > n - i:
                break
        return ans - 1

    def hIndex_(self, citations: List[int]) -> int:
        """二分查找
        """
        l, r, n = 0, len(citations) - 1, len(citations)
        while l <= r:
            mid = l + (r - l) // 2
            if citations[mid] >= n - mid:
                r = mid - 1
            else:
                l = mid + 1
        return n - l
