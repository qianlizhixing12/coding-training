from functools import reduce


class Solution:

    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        for c in columnTitle:
            result = result * 26 + ord(c) - ord('A') + 1
        return result

    def titleToNumber_(self, columnTitle: str) -> int:
        return reduce(lambda x, y: x * 26 + ord(y) - ord('A') + 1, columnTitle, 0)