from typing import List


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        rst = []
        if root == None:
            return rst
        level = [root]
        while level:
            rst.append([])
            next_level = []
            for node in level:
                rst[-1].append(node.val)
                if node.left != None:
                    next_level.append(node.left)
                if node.right != None:
                    next_level.append(node.right)
            level = next_level
        return rst


if __name__ == "__main__":
    root = TreeNode(3)
    Solution().levelOrder(root)