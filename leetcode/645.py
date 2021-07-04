from typing import List


class Solution:

    def findErrorNums(self, nums: List[int]) -> List[int]:
        error_num, unique, ans = len(nums), set(), []
        for i, num in enumerate(nums):
            error_num ^= (i ^ num)
            if num in unique:
                ans.append(num)
            unique.add(num)
        ans.append(error_num ^ ans[0])
        return ans
