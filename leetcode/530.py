# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def getMinimumDifference(self, root: TreeNode) -> int:

        def dfs(root: TreeNode):
            nonlocal ans
            nonlocal pre
            if not root:
                return
            dfs(root.left)
            if pre:
                ans = min(ans, abs(root.val - pre.val))
            pre = root
            dfs(root.right)

        ans = float('inf')
        pre = None
        dfs(root)
        return ans