from typing import List
import collections


class Solution:

    def majorityElement(self, nums: List[int]) -> int:
        half = len(nums) >> 1
        tb = collections.defaultdict(int)
        for num in nums:
            tb[num] += 1
            if tb[num] > half:
                return num
        return -1


if __name__ == "__main__":
    print(Solution().majorityElement([1, 2, 3, 2, 2, 2, 5, 4, 2]))
