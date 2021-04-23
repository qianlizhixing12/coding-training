from typing import List


class Solution:

    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        # dpc记录最大个数
        dpc = [1 for i in range(len(nums))]
        # dpp记录最大个数时对应最大因数位置
        dpp = [i for i in range(len(nums))]
        # maxc全局最大个数
        maxc = 1
        # maxv全局最大个数对应值对应位置
        maxi = 0
        for i in range(1, len(nums)):
            for j in range(0, i):
                # nums[i]能被nums[j]整除，nums[j]满足条件的子集基础上添加nums[i]也满足
                # 比如3满足[1,2,3], 6在此基础上[1,2,3,6]也满足条件
                if nums[i] % nums[j] == 0 and dpc[i] < dpc[j] + 1:
                    dpc[i], dpp[i] = dpc[j] + 1, j
            if dpc[i] > maxc:
                maxc = dpc[i]
                maxi = i
        # 倒叙搜索添加
        res = []
        index = maxi
        while dpp[index] != index:
            res.append(nums[index])
            index = dpp[index]
        res.append(nums[index])
        return res
