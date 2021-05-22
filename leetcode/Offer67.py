class Solution:
    def strToInt(self, str: str) -> int:
        start = False
        ans = 0
        div = 1
        for c in str:
            if c == "+" and not start:
                start = True
            elif c == "-" and not start:
                div = -1
                start = True
            elif c == " " and not start:
                continue
            elif c.isdigit():
                ans = ans * 10 + int(c)
                start = True
            else:
                break
        ans *= div
        if ans < -2147483648:
            return -2147483648
        if ans > 2147483647:
            return 2147483647
        return ans
