import collections


class Solution:

    def CheckPermutation1(self, s1: str, s2: str) -> bool:
        s1_ = sorted(s1)
        s2_ = sorted(s2)
        return s1_ == s2_

    def CheckPermutation(self, s1: str, s2: str) -> bool:
        s1_ = collections.Counter(s1)
        s2_ = collections.Counter(s2)
        return s1_ == s2_


if __name__ == "__main__":
    print(Solution().CheckPermutation("abc", "bca"))
