from typing import List


class Solution:

    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = ((r - l) >> 1) + l
            if nums[mid] == target:
                return mid
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
        return -1


if __name__ == "__main__":
    # print(Solution().search([4, 5, 6, 7, 0, 1, 2], 0))
    print(Solution().search([1, 3], 3))
