class Solution:

    def myPow(self, x: float, n: int) -> float:

        def dfs(x: float, n: int) -> float:
            if n == 0:
                return 1
            elif n == 1:
                return x
            val = dfs(x, n >> 1)
            return val * val * (x if n & 1 else 1)

        dir = n >= 0
        if not dir:
            n = -n
        return dfs(x, n) if dir else 1 / dfs(x, n)
