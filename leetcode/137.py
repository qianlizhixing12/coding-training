from typing import List
from collections import Counter


class Solution:

    def singleNumber(self, nums: List[int]) -> int:
        count = Counter(nums)
        for num, times in count.items():
            if times == 1:
                return num
