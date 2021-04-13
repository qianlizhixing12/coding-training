# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def lowestCommonAncestor_(self, root: 'TreeNode', p: 'TreeNode',
                              q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        if root == p or root == q:
            return root
        left = self.lowestCommonAncestor_(root.left, p, q)
        right = self.lowestCommonAncestor_(root.right, p, q)
        if left and right:
            return root
        if left:
            return left
        if right:
            return right
        return None

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode',
                             q: 'TreeNode') -> 'TreeNode':
        if not root or root == p or root == q:
            return root
        if ((root.val - p.val) * (root.val - q.val)) < 0:
            return root
        elif (root.val > p.val) and (root.val > q.val):
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return self.lowestCommonAncestor(root.right, p, q)