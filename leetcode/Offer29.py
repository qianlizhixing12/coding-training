from typing import List


class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return matrix
        t = 0
        b = len(matrix) - 1
        l = 0
        r = len(matrix[0]) - 1
        rst = []
        while True:
            for i in range(l, r + 1):
                rst.append(matrix[t][i])
            t += 1
            if t > b:
                break
            for i in range(t, b + 1):
                rst.append(matrix[i][r])
            r -= 1
            if r < l:
                break
            for i in range(r, l - 1, -1):
                rst.append(matrix[b][i])
            b -= 1
            if b < t:
                break
            for i in range(b, t - 1, -1):
                rst.append(matrix[i][l])
            l += 1
            if l > r:
                break
        return rst