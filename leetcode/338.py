from typing import List


class Solution:

    def countBits(self, num: int) -> List[int]:
        rst = [0] * (num + 1)
        for i in range(num + 1):
            rst[i] = rst[i >> 1] + (i & 1)
        return rst