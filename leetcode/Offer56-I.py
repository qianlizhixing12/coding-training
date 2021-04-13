from typing import List
import functools
import pytest


class Solution:

    def singleNumbers(self, nums: List[int]) -> List[int]:
        res = functools.reduce(lambda x, y: x ^ y, nums, 0)
        # 分组
        group = 1
        while (group & res) == 0:
            group <<= 1
        # group中1在的那个bit位，a,b不同
        a = b = 0
        for num in nums:
            if num & group == 0:
                a ^= num
            else:
                b ^= num
        return [a, b]


class TestDemo(object):

    def test1(self):
        assert Solution().singleNumbers([4, 1, 4, 6]) == [6, 1]


if __name__ == "__main__":
    pytest.main(['Offer56-I.py'])