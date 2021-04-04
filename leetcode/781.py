from typing import List
import collections


class Solution:

    def numRabbits(self, answers: List[int]) -> int:
        cache = collections.Counter(answers)
        return sum(((num + value) // (value + 1) * (value + 1)
                    for value, num in cache.items()))


if __name__ == "__main__":
    Solution().numRabbits([0, 0, 1, 1, 1])
