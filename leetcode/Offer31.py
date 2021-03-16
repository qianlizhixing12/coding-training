from typing import List


class Solution:

    def validateStackSequences(self, pushed: List[int],
                               popped: List[int]) -> bool:
        stack = []
        n = len(popped)
        j = 0
        for i in pushed:
            stack.append(i)
            while len(stack) > 0 and j < n and stack[-1] == popped[j]:
                stack.pop()
                j += 1
        return j == n
