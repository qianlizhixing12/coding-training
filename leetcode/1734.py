from typing import List


class Solution:

    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded)
        ans = [0] * (n + 1)
        for i in range(1, n + 2):
            ans[0] ^= i

        for i in range(1, n, 2):
            ans[0] ^= encoded[i]

        for i in range(n):
            ans[i + 1] = encoded[i] ^ ans[i]

        return ans
