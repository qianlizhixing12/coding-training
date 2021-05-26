class Solution:

    def reverseParentheses(self, s: str) -> str:
        stack = []
        for c in s:
            if c == ")":
                tmp = []
                while stack:
                    t = stack.pop()
                    if t == "(":
                        break
                    tmp.append(t)
                stack.extend(tmp)
            else:
                stack.append(c)
        return "".join(stack)