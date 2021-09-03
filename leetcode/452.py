from typing import List


class Solution:

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda elem: elem[0])
        count, r = 1, float("inf")

        for point in points:
            if point[0] > r:
                count += 1
                r = point[1]
            else:
                r = min(r, point[1])

        return count

    def findMinArrowShots_(self, points: List[List[int]]) -> int:
        points.sort(key=lambda elem: elem[1])
        count, r = 1, points[0][1]

        for point in points:
            if point[0] > r:
                count += 1
                r = point[1]

        return count
