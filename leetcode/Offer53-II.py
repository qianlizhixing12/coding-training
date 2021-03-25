from typing import List


class Solution:

    def missingNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            if num != result:
                return result
            result += 1
        return result

    def missingNumber_(self, nums: List[int]) -> int:
        '''
        二分查找
        '''
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) >> 1
            if nums[mid] == mid:
                l = mid + 1
            else:
                r = mid - 1
        return l