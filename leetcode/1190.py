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

    def reverseParentheses_(self, s: str) -> str:
        stack = []
        tmp = ""
        for c in s:
            if c == "(":
                stack.append(tmp)
                tmp = ""
            elif c == ")":
                tmp = "".join(reversed(tmp))
                if stack:
                    tmp = stack.pop() + tmp
            else:
                tmp += c
        return tmp
