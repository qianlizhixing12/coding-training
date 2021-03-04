from typing import List


class Solution:

    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        row = len(matrix)
        col = len(matrix[0]) - 1
        r = 0
        while r < row and col >= 0:
            if matrix[r][col] == target:
                return True
            elif matrix[r][col] > target:
                col -= 1
            else:
                r += 1
        return False


if __name__ == "__main__":
    Solution().findNumberIn2DArray(
        [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22],
         [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]], 5)
