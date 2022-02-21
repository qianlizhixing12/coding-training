from typing import List


class Solution:

    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded)
        perm = [0]

        for i in range(1, n + 2):
            perm[0] ^= i

        for i in range(1, n, 2):
            perm[0] ^= encoded[i]

        for i in range(n):
            perm.append(encoded[i] ^ perm[i])

        return perm
