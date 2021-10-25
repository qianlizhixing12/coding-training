from typing import List


class Solution:

    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        count, left = 0, intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] < left:
                count += 1
            else:
                left = intervals[i][1]
        return count
