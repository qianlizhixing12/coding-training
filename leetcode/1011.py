from typing import List


class Solution:

    def shipWithinDays(self, weights: List[int], D: int) -> int:

        def check_need_day(weights, load):
            need = 1
            loads = 0
            for weight in weights:
                if loads + weight > load:
                    need += 1
                    loads = 0
                loads += weight
            return need

        l = max(weights)
        r = sum(weights)
        while l < r:
            mid = ((r - l) >> 1) + l
            if check_need_day(weights, mid) > D:
                l = mid + 1
            else:
                r = mid
        return l