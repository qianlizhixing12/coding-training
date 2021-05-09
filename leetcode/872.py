from typing import List


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:

        def dfs(root: TreeNode, ans: List[TreeNode]):
            if not root:
                return

            if (not root.left) and (not root.right):
                ans.append(root.val)
                return

            dfs(root.left, ans)
            dfs(root.right, ans)

        ans1, ans2 = [], []
        dfs(root1, ans1)
        dfs(root2, ans2)
        return ans1 == ans2
