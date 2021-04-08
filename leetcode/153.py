from typing import List


class Solution:

    def findMin(self, nums: List[int]) -> int:
        l, r, ans = 0, len(nums) - 1, float('inf')
        while l <= r:
            mid = l + ((r - l) >> 1)
            # l到mid有序
            if nums[mid] >= nums[l]:
                ans = min(ans, nums[l])
                l = mid + 1
            # mid到r有序
            else:
                ans = min(ans, nums[mid])
                r = mid - 1
        return ans

    def findMin_(self, nums: List[int]) -> int:
        '''
        直接找最小值的位置
        '''
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + ((r - l) >> 1)
            # mid到r有序
            if nums[mid] < nums[r]:
                r = mid
            else:
                l = mid + 1
        return nums[l]


if __name__ == "__main__":
    Solution().findMin([2, 1])
