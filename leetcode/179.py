from typing import List
import functools
import pytest


class Solution:

    def largestNumber_(self, nums: List[int]) -> str:

        def cmp(s1: str, s2: str) -> int:
            '''
            字符串排序
            '''
            i = 0
            s1, s2 = s1 + s2, s2 + s1
            l = len(s1)
            while i < l:
                if s1[i] != s2[i]:
                    return 1 if s1[i] > s2[i] else -1
                i += 1
            return 0

        s = list(map(str, nums))
        s.sort(key=functools.cmp_to_key(cmp), reverse=True)
        return str(int(''.join(s)))

    def largestNumber(self, nums: List[int]) -> str:
        # s = list(map(str, nums))
        s = [str(num) for num in nums]
        cmp = lambda x, y: 1 if x + y <= y + x else -1
        s.sort(key=functools.cmp_to_key(cmp))
        s = ''.join(s)
        return s if s[0] != '0' else '0'


@pytest.fixture
def solution():
    return Solution()


class TestDemo(object):

    def test1(self, solution):
        assert solution.largestNumber([10, 2]) == '210'

    def test2(self, solution):
        assert solution.largestNumber([3, 30, 34, 5, 9]) == '9534330'

    def test3(self, solution):
        assert solution.largestNumber([8308, 8308, 830]) == '83088308830'

    def test4(self, solution):
        assert solution.largestNumber([0, 0]) == '0'


if __name__ == '__main__':
    pytest.main(['179.py'])