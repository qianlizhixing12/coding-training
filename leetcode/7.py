class Solution:

    def reverse(self, x: int) -> int:
        ans = 0
        x, dir = (x, 1) if x >= 0 else (-x, -1)
        while x > 0:
            ans = ans * 10
            ans += x % 10
            x = x // 10
        ans = dir * ans
        return ans if ans <= 2147483647 and ans >= -2147483648 else 0
