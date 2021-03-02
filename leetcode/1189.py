import collections


class Solution:

    def maxNumberOfBalloons(self, text: str) -> int:
        # word = collections.Counter('balloon')
        # rst = len(text)
        # for c, num in word.items():
        #     rst = min(rst, text.count(c) // num)
        # return rst
        return min(
            text.count(c) // num
            for c, num in collections.Counter('balloon').items())


if __name__ == "__main__":
    Solution().maxNumberOfBalloons("nlaebolko")