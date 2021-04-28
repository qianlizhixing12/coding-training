import math


class Solution:

    def judgeSquareSum(self, c: int) -> bool:
        r = int(math.sqrt(c))
        l = 0
        while l <= r:
            cur = l * l + r * r
            if cur == c:
                return True
            elif cur > c:
                r -= 1
            else:
                l += 1
        return False