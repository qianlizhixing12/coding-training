from typing import List


class Solution:

    def maxSubArray(self, nums: List[int]) -> int:
        ans, sum = float('-inf'), float('-inf')
        for num in nums:
            if sum < 0:
                sum = num
            else:
                sum += num
            ans = max(ans, sum)
        return ans