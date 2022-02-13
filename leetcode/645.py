from functools import cache
from typing import List
from collections import defaultdict


class Solution:

    def findErrorNums(self, nums: List[int]) -> List[int]:
        cache = defaultdict(int)
        error, miss = 0, 0

        for i, num in enumerate(nums):
            cache[i + 1] += 1
            cache[num] += 1

        for k, v in cache.items():
            if v == 1:
                miss = k
            if v == 3:
                error = k

        return [error, miss]
