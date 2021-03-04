class Solution:

    def replaceSpace(self, s: str) -> str:
        return '%20'.join(s.split(' '))

    def replaceSpace_(self, s: str) -> str:
        rst = ''
        i = 0
        for j in range(len(s)):
            if (s[j] == ' '):
                rst += s[i:j] + '%20'
                i = j + 1
        rst += s[i:]
        return rst