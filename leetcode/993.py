from typing import Tuple


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def dfs(root: TreeNode, x: int, y: int, parent: TreeNode, depth: int):
            nonlocal xdepth, ydepth, xparent, yparent
            if not root:
                return

            if root.val == x:
                xparent = parent
                xdepth = depth
                return
            elif root.val == y:
                yparent = parent
                ydepth = depth
                return

            dfs(root.left, x, y, root, depth+1)
            dfs(root.right, x, y, root, depth+1)

        xdepth, ydepth, xparent, yparent = 0, 0, None, None
        dfs(root, x, y, None, 0)
        return xdepth == ydepth and xparent != yparent
