class Solution:

    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        num1, num2 = 0, 1
        for _ in range(2, n + 1):
            num1, num2 = num2, num1 + num2
        return num2 % 1000000007
