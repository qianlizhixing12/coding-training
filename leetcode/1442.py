class Solution:

    def countTriplets(self, arr: List[int]) -> int:
        cache = [0]
        result = 0

        for num in arr:
            cache.append(cache[-1] ^ num)

        n = len(cache)
        for i in range(n):
            for j in range(i + 1, n):
                if cache[i] == cache[j]:
                    result += j - i - 1

        return result