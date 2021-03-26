# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def isBalanced(self, root: TreeNode) -> bool:

        def bfs(root: TreeNode):
            if not root:
                return [True, 0]
            left = bfs(root.left)
            if not left[0]:
                return left
            right = bfs(root.right)
            if not right[0]:
                return right
            return [abs(left[1] - right[1]) <= 1, max(left[1], right[1]) + 1]

        return bfs(root)[0]
