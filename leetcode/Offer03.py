from typing import List
import collections


class Solution:

    def findRepeatNumber(self, nums: List[int]) -> int:
        cache = collections.defaultdict(int)
        for num in nums:
            if cache[num] != 0:
                return num
            cache[num] += 1
        return -1

    def findRepeatNumber1(self, nums: List[int]) -> int:
        cache = set()
        for num in nums:
            if num in cache:
                return num
            cache.add(num)
        return -1

    def findRepeatNumber2(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        for i in range(1, n):
            if nums[i] == nums[i - 1]:
                return nums[i]
        return -1


if __name__ == "__main__":
    print(Solution().findRepeatNumber([2, 3, 1, 0, 2, 5, 3]))