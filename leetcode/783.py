# Definition for a binary tree node.
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def minDiffInBST(self, root: TreeNode) -> int:

        def dfs(root: TreeNode):
            nonlocal ans
            nonlocal cur
            if not root:
                return
            dfs(root.left)
            if cur:
                ans = min(ans, abs(root.val - cur.val))
            cur = root
            dfs(root.right)

        ans = float('inf')
        cur = None
        dfs(root)
        return ans