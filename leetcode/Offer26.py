# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:

        def dfs(A: TreeNode, B: TreeNode) -> bool:
            if B == None:
                return True
            if A == None or A.val != B.val:
                return False
            return dfs(A.left, B.left) and dfs(A.right, B.right)

        if A == None or B == None:
            return False

        return dfs(A, B) or self.isSubStructure(
            A.left, B) or self.isSubStructure(A.right, B)
