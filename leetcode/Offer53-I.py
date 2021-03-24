from typing import List


class Solution:

    def search(self, nums: List[int], target: int) -> int:
        '''
        O(n)
        '''
        result = 0
        for num in nums:
            if num == target:
                result += 1
            elif num > target:
                return result
        return result

    def search_(self, nums: List[int], target: int) -> int:
        '''
        二分查找，O(logN)
        '''

        def binary_search(nums, l, r, target):
            if l > r:
                return 0
            elif l == r:
                return 1 if target == nums[l] else 0
            if nums[l] > target or nums[r] < target:
                return 0
            mid = (l + r) >> 1
            if nums[mid] == target:
                result = 1
                tmp = mid - 1
                while tmp >= l and nums[tmp] == target:
                    result += 1
                    tmp -= 1
                tmp = mid + 1
                while tmp <= r and nums[tmp] == target:
                    result += 1
                    tmp += 1
                return result
            elif nums[mid] > target:
                return binary_search(nums, l, mid - 1, target)
            else:
                return binary_search(nums, mid + 1, r, target)

        return binary_search(nums, 0, len(nums) - 1, target)