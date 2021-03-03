from typing import List


class Solution:

    def maxSubArray(self, nums: List[int]) -> int:
        '''
        暴力解法
        '''
        rst = float('-inf')
        n = len(nums)
        for i in range(n):
            sum = 0
            for j in range(i, n):
                sum += nums[j]
                rst = max(rst, sum)
        return rst


class Solution1:

    def maxSubArray(self, nums: List[int]) -> int:
        '''
        动态规划
        '''
        n = len(nums)
        cache = [0] * n
        cache[0] = nums[0]
        rst = nums[0]
        for i in range(1, n):
            if cache[i - 1] <= 0:
                cache[i] = nums[i]
            else:
                cache[i] = cache[i - 1] + nums[i]
            rst = max(rst, cache[i])
        return rst


class Solution2:

    def maxSubArray(self, nums: List[int]) -> int:
        '''
        动态规划 优化空间
        '''
        n = len(nums)
        sum = nums[0]
        rst = nums[0]
        for i in range(1, n):
            if sum <= 0:
                sum = nums[i]
            else:
                sum += nums[i]
            rst = max(rst, sum)
        return rst


if __name__ == "__main__":
    Solution1().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])
