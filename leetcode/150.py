from typing import List


class Solution:

    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == '+':
                stack[-2] += stack[-1]
                stack.pop()
            elif token == '-':
                stack[-2] -= stack[-1]
                stack.pop()
            elif token == '*':
                stack[-2] *= stack[-1]
                stack.pop()
            elif token == '/':
                stack[-2] = int(stack[-2] / stack[-1])
                stack.pop()
            else:
                stack.append(int(token))
        return stack[0]


if __name__ == "__main__":
    Solution().evalRPN(
        ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"])
