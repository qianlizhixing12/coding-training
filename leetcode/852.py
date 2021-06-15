from typing import List


class Solution:

    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) // 2
            if arr[mid] > arr[left]:
                left += 1
            else:
                right -= 1
        return left
