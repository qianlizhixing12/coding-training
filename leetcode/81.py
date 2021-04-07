from typing import List


class Solution:

    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = ((r - l) >> 1) + l
            if nums[mid] == target:
                return True
            if nums[l] == nums[mid] and nums[r] == nums[mid]:
                l += 1
                r -= 1
                continue
            # l到mid有序情况下
            if nums[l] <= nums[mid]:
                if nums[mid] > target and nums[l] <= target:
                    r = mid - 1
                else:
                    l = mid + 1
            #mid到r有序
            else:
                if nums[mid] < target and nums[r] >= target:
                    l = mid + 1
                else:
                    r = mid - 1
        return False