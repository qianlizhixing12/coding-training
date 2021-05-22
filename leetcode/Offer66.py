from typing import List


class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        n = len(a)
        left, right, ans = [1] * n, [1] * n, [1] * n
        for i in range(1, n):
            left[i] = left[i - 1] * a[i - 1]
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * a[i + 1]
        for i in range(n):
            ans[i] = left[i] * right[i]
        return ans
