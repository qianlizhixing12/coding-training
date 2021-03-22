from typing import List
import collections


class Solution:

    def permutation(self, s: str) -> List[str]:

        def dfs(n, s):
            if n == 0:
                result.append(s)
                return
            for c in tb:
                if tb[c] == 0:
                    continue
                tb[c] -= 1
                dfs(n - 1, s + c)
                tb[c] += 1

        tb = collections.defaultdict(int)
        for c in s:
            tb[c] += 1
        result = []
        dfs(len(s), '')
        return result


if __name__ == "__main__":
    print(Solution().permutation('abc'))
