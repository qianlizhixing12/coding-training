from typing import List
from copy import deepcopy


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:

        def dfs(root, path, sum):
            if root == None:
                return

            path.append(root.val)
            dfs(root.left, path, sum + root.val)
            dfs(root.right, path, sum + root.val)
            if root.left == None and root.right == None and sum + root.val == target:
                ans.append(deepcopy(path))
            path.pop()

        ans = []
        dfs(root, [], 0)
        return ans