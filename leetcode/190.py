class Solution:

    def reverseBits(self, n: int) -> int:
        if n == 0:
            return n
        ans = 0
        for i in range(32):
            if (1 << i) & n:
                ans += 1 << (31 - i)
        return ans


if __name__ == "__main__":
    Solution().reverseBits(43261596)