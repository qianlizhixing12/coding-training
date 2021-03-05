from typing import List, Dict


# Definition for a binary tree node.
class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution1:

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        '''
        和主题105相同
        '''
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        return root


class Solution2:

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        '''
        每次不产生新数组，传递相对索引
        '''
        return self._buildTree(preorder, inorder, 0,
                               len(preorder) - 1, 0,
                               len(inorder) - 1)

    def _buildTree(self, preorder: List[int], inorder: List[int], p1: int,
                   p2: int, i1: int, i2: int) -> TreeNode:
        if p1 > p2:
            return None
        root = TreeNode(preorder[p1])
        if p1 == p2:
            return root
        mid = inorder.index(preorder[p1])
        root.left = self._buildTree(preorder, inorder, p1 + 1, mid - i1 + p1,
                                    i1, mid - 1)
        root.right = self._buildTree(preorder, inorder, mid - i1 + p1 + 1, p2,
                                     mid + 1, i2)
        return root


class Solution3:

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        '''
        每次不产生新数组，传递相对索引
        优化不用index方法，用字典快速查找
        '''
        cache = {}
        for i in range(len(inorder)):
            cache[inorder[i]] = i
        return self._buildTree(cache, preorder, inorder, 0,
                               len(preorder) - 1, 0,
                               len(inorder) - 1)

    def _buildTree(self, cache: Dict[int, int], preorder: List[int],
                   inorder: List[int], p1: int, p2: int, i1: int,
                   i2: int) -> TreeNode:
        if p1 > p2:
            return None
        root = TreeNode(preorder[p1])
        if p1 == p2:
            return root
        mid = cache[preorder[p1]]
        root.left = self._buildTree(cache, preorder, inorder, p1 + 1,
                                    mid - i1 + p1, i1, mid - 1)
        root.right = self._buildTree(cache, preorder, inorder,
                                     mid - i1 + p1 + 1, p2, mid + 1, i2)
        return root


# Solution2().buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
Solution2().buildTree([1, 2, 3], [3, 2, 1])
