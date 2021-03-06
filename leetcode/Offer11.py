from typing import List


class Solution:

    def minArray(self, numbers: List[int]) -> int:
        '''
        暴力循环
        '''
        for i in range(1, len(numbers)):
            if (numbers[i - 1] > numbers[i]):
                return numbers[i]
        return numbers[0]

    def minArray_(self, numbers: List[int]) -> int:
        '''
        二分查找
        '''
        v = self.binary_search(numbers, 0, len(numbers) - 1)
        return v if v != None else numbers[0]

    def binary_search(self, numbers: List[int], left: int, right: int) -> int:
        if left >= right:
            return None
        mid = left + ((right - left) >> 1)
        if numbers[mid] > numbers[mid + 1]:
            return numbers[mid + 1]
        else:
            lv = self.binary_search(numbers, left, mid)
            rv = self.binary_search(numbers, mid + 1, right)
            return lv if lv != None else rv

    def minArray__(self, numbers: List[int]) -> int:
        '''
        二分查找
        '''
        left, right = 0, len(numbers) - 1
        while left < right:
            mid = left + ((right - left) >> 1)
            if numbers[mid] < numbers[right]:
                right = mid
            elif numbers[mid] > numbers[right]:
                left = mid + 1
            else:
                right -= 1
        return numbers[left]


if __name__ == "__main__":
    Solution().minArray_([2, 2, 2, 0, 1])
