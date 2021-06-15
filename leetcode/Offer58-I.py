class Solution:

    def reverseWords(self, s: str) -> str:
        return " ".join(reversed([c for c in s.split(sep=" ") if c]))