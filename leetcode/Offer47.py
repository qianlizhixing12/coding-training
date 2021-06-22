from typing import List


class Solution:

    def maxValue(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                tmp = 0
                if i != 0:
                    tmp = max(tmp, grid[i - 1][j])
                if j != 0:
                    tmp = max(tmp, grid[i][j - 1])
                grid[i][j] += tmp
        return grid[-1][-1]