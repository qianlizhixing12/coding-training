from typing import List


class Solution:

    def totalHammingDistance(self, nums: List[int]) -> int:

        def hammingDistance(x: int, y: int) -> int:
            n, ans = x ^ y, 0
            while n:
                n &= n - 1
                ans += 1
            return ans

        ans, n = 0, len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                ans += hammingDistance(nums[i], nums[j])
        return ans

    def totalHammingDistance_(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(32):
            c = 0
            for num in nums:
                c += (num >> i) & 1
            ans += c * (n - c)
        return ans
