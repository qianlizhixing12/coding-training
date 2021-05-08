from typing import List


class Solution:

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:

        def canMake(mid):
            m_, k_ = 0, 0
            for num in bloomDay:
                if m_ == m:
                    break
                if num > mid:
                    k_ = 0
                    continue
                k_ += 1
                if k_ == k:
                    k_ = 0
                    m_ += 1
            return m_ == m

        if m * k > len(bloomDay):
            return -1

        l, r = 1, max(bloomDay)
        while l < r:
            mid = l + ((r - l) >> 1)
            if canMake(mid):
                r = mid
            else:
                l = mid + 1
        return l
