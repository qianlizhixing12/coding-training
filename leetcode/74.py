from typing import List


class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        l, r = 0, m * n - 1
        while l <= r:
            mid = (l + r) >> 1
            val = matrix[mid // n][mid % n]
            if val == target:
                return True
            elif val > target:
                r = mid - 1
            else:
                l = mid + 1
        return False


if __name__ == "__main__":
    Solution().searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]],
                            3)
