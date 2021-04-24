from typing import List


class Solution:

    def combinationSum4(self, nums: List[int], target: int) -> int:
        '''暴力循环
        '''

        def back(target: int):
            nonlocal rst

            for num in nums:
                if num > target:
                    break
                elif num == target:
                    rst += 1
                    break
                else:
                    back(target - num)

        nums.sort()
        rst = 0
        back(target)
        return rst

    def combinationSum4_(self, nums: List[int], target: int) -> int:
        '''缓存备忘录
        '''

        def back(target: int):
            if target in cache:
                return cache[target]

            rst = 0
            for num in nums:
                if num == target:
                    rst += 1
                elif num < target:
                    rst += back(target - num)

            cache[target] = rst
            return rst

        cache = {}
        return back(target)

    def combinationSum4__(self, nums: List[int], target: int) -> int:
        '''动态规划
        '''
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(target + 1):
            for num in nums:
                if i >= num:
                    dp[i] += dp[i - num]
        return dp[target]