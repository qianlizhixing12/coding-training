from typing import List


class Solution:

    def minimumTotal(self, triangle: List[List[int]]) -> int:
        '''
        暴力解法
        '''
        return self.dfs(triangle, len(triangle), 0, 0)

    def dfs(self, triangle: List[List[int]], size: int, row: int,
            col: int) -> int:
        if size == row:
            return 0
        return min(self.dfs(triangle, size, row + 1, col),
                   self.dfs(triangle, size, row + 1,
                            col + 1)) + triangle[row][col]


class Solution1:

    def minimumTotal(self, triangle: List[List[int]]) -> int:
        '''
        缓存备忘录
        '''
        self.help = {}
        return self.dfs(triangle, len(triangle), 0, 0)

    def dfs(self, triangle: List[List[int]], size: int, row: int,
            col: int) -> int:
        if size == row:
            return 0
        key = (
            row,
            col,
        )
        if key in self.help:
            return self.help[key]
        self.help[key] = min(self.dfs(triangle, size, row + 1, col),
                             self.dfs(triangle, size, row + 1,
                                      col + 1)) + triangle[row][col]
        return self.help[key]


class Solution2:

    def minimumTotal(self, triangle: List[List[int]]) -> int:
        '''
        动态规划
        '''
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                # triangle[i][j] += min(triangle[i + 1][j],
                #                       triangle[i + 1][j + 1])
                triangle[i][j] += min(triangle[i + 1][j:j + 2])
        return triangle[0][0]


if __name__ == "__main__":
    for i in range(5, -1, -1):
        print(i)