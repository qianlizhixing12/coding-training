from typing import List
from heapq import heapify


class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m, n, nums = len(matrix), len(matrix[0]), [matrix[0][0]]

        for i in range(1, n):
            matrix[0][i] ^= matrix[0][i - 1]
            nums.append(matrix[0][i])
        for i in range(1, m):
            matrix[i][0] ^= matrix[i - 1][0]
            nums.append(matrix[i][0])
        for a in range(1, m):
            for b in range(1, n):
                matrix[a][b] ^= matrix[a - 1][b] ^ matrix[a][b - 1] ^ matrix[a - 1][b - 1]
                nums.append(matrix[a][b])

        nums.sort()
        return nums[-k]
