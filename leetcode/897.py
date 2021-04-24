# Definition for a binary tree node.
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def increasingBST(self, root: TreeNode) -> TreeNode:

        def dfs(root: TreeNode):
            nonlocal head
            nonlocal cur
            if not root:
                return None
            dfs(root.left)
            if not head:
                head = root
            if not cur:
                cur = root
            else:
                root.left = None
                cur.right = root
                cur = cur.right
            dfs(root.right)

        head, cur = None, None
        dfs(root)
        return head