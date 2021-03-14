class Solution:

    def isValidSerialization(self, preorder: str) -> bool:
        if not preorder:
            return False
        stack = []
        preorder = preorder.split(',')
        n = len(preorder)
        for i, c in enumerate(preorder):
            stack.append(c)
            while len(stack) >= 2 and stack[-1] == '#' and stack[-2] == '#':
                stack.pop()
                stack.pop()
                stack.pop()
                stack.append('#')
            if len(stack) == 1 and stack[0] == '#':
                if i == n - 1:
                    return True
                else:
                    return False
        return False


print(Solution().isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"))