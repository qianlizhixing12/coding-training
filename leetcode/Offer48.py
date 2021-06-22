from collections import defaultdict


class Solution:

    def lengthOfLongestSubstring(self, s: str) -> int:
        count, i, ans = defaultdict(int), 0, 0
        for j, c in enumerate(s):
            if count[c] != 0:
                for k in range(i, j):
                    if s[k] == c:
                        i = k + 1
                        break
                count[c] -= 1
            count[c] += 1
            ans = max(ans, j - i + 1)
        return ans