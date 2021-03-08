from typing import List


class Solution:

    def printNumbers(self, n: int) -> List[int]:
        return list(range(1, pow(10, n)))
