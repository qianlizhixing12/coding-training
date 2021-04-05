from typing import List


class Solution:

    def insert(self, intervals: List[List[int]],
               newInterval: List[int]) -> List[List[int]]:
        ans = []
        n = len(intervals)
        pos = 0
        # 找到左边界
        while pos < n and intervals[pos][1] < newInterval[0]:
            ans.append(intervals[pos])
            pos += 1
        # 找到右边界
        while pos < n and intervals[pos][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[pos][0])
            newInterval[1] = max(newInterval[1], intervals[pos][1])
            pos += 1
        ans.append(newInterval)
        # 余下元素
        while pos < n:
            ans.append(intervals[pos])
            pos += 1
        return ans


if __name__ == "__main__":
    print(Solution().insert(intervals=[[1, 3], [6, 9]], newInterval=[2, 5]))
    print(Solution().insert(intervals=[[1, 2], [3, 5], [6, 7], [8, 10],
                                       [12, 16]],
                            newInterval=[4, 8]))
    print(Solution().insert([[1, 5]], [0, 0]))