# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def kthLargest(self, root: TreeNode, k: int) -> int:
        '''
        遍历顺序，右-根-左
        '''

        def dfs(root: TreeNode) -> int:
            if root == None:
                return
            dfs(root.right)
            result.append(root.val)
            dfs(root.left)

        result = []
        dfs(root)
        return result[k - 1]

    def kthLargest_(self, root: TreeNode, k: int) -> int:
        '''
        遍历顺序，右-根-左
        '''

        def dfs(root: TreeNode):
            nonlocal k
            if root == None:
                return
            dfs(root.right)
            if k == 0:
                return
            k -= 1
            if k == 0:
                self.ans = root.val
                return
            dfs(root.left)

        self.ans = 0
        dfs(root)
        return self.ans