from typing import List


class Solution:

    def partition(self, s: str) -> List[List[str]]:
        rst = []
        self.dfs(rst, s, [])
        return rst

    def dfs(self, rst: List[List[str]], s: str, cur: List[str]):
        if s == '':
            rst.append(cur)
            return
        for i in range(1, len(s) + 1):
            if self.is_palindrome(s[:i]):
                self.dfs(rst, s[i:], cur)

    def is_palindrome(self, s: str):
        return s == s[::-1]