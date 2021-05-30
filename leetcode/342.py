class Solution:

    def isPowerOfFour(self, n: int) -> bool:
        if n == 0:
            return False
        power = 0
        while n != 1 and (n & (n - 1)) == 0:
            power += 1
            n >>= 1
        return n == 1 and power % 2 == 0

    def isPowerOfFour_(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0 and (n & 0xaaaaaaaa) == 0
