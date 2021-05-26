class Solution:

    def hammingDistance(self, x: int, y: int) -> int:
        n, ans = x ^ y, 0
        while n:
            n &= n - 1
            ans += 1
        return ans
