# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def isSymmetric(self, root: TreeNode) -> bool:

        def dfs(left: TreeNode, right: TreeNode) -> bool:
            if left == None and right == None:
                return True
            elif left == None or right == None:
                return False
            elif left.val != right.val:
                return False
            return dfs(left.left, right.right) and dfs(left.right, right.left)

        if root == None:
            return True
        return dfs(root.left, root.right)