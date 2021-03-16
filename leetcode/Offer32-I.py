from typing import List


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def levelOrder(self, root: TreeNode) -> List[int]:
        rst = []
        if root == None:
            return rst
        level = [root]
        while level:
            next_level = []
            for node in level:
                if node:
                    rst.append(node.val)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            level = next_level
        return rst