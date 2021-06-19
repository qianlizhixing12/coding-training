class Solution:

    def sumNums(self, n: int) -> int:

        def helper(n):
            nonlocal result
            n >= 1 and helper(n - 1)
            result += n

        result = 0
        helper(n)
        return result