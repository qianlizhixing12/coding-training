from typing import List


class Solution:

    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + ((r - l) >> 1)
            if nums[l] == nums[r]:
                r -= 1
                continue
            # mid到r有序
            if nums[mid] <= nums[r]:
                r = mid
            else:
                l = mid + 1
        return nums[l]


if __name__ == "__main__":
    print(Solution().findMin([1, 3, 5]))
    print(Solution().findMin([2, 2, 2, 0, 1]))
    print(Solution().findMin([1, 3, 3]))
