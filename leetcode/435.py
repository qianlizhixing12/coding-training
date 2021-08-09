from typing import List


class Solution:

    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda elem: elem[1])
        total, prev = 0, intervals[0][1]
        for i in range(1, len(intervals)):
            if prev > intervals[i][0]:
                total += 1
            else:
                prev = intervals[i][1]
        return total
