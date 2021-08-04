from typing import List


class Solution:

    def triangleNumber(self, nums: List[int]) -> int:
        """排序后二分查找 N*N*logN
        """
        ans, n = 0, len(nums)
        if n < 3:
            return 0

        nums.sort()
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                l, r, target = j + 1, n - 1, nums[i] + nums[j]
                while l <= r:
                    mid = (l + r) >> 1
                    if nums[mid] >= target:
                        r = mid - 1
                    else:
                        l = mid + 1
                ans += l - j - 1

        return ans

    def triangleNumber_(self, nums: List[int]) -> int:
        """排序后双指针(快慢指针) N*N
        """
        ans, n = 0, len(nums)
        if n < 3:
            return 0

        nums.sort()
        for i in range(n - 2):
            k = i
            for j in range(i + 1, n - 1):
                while k < n and nums[k] < nums[i] + nums[j]:
                    k += 1
                ans += max(0, k - j - 1)

        return ans
