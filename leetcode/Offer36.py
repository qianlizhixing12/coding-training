# Definition for a Node.
class Node:

    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def treeToDoublyList(self, root: Node) -> Node:

        def dfs(root: Node) -> Node:
            nonlocal cur
            if root == None:
                return None
            dfs(root.left)
            cur.right = root
            root.left = cur
            cur = root
            dfs(root.right)

        if not root:
            return root
        head = Node(0)
        cur = head
        dfs(root)
        head.right.left, cur.right = cur, head.right
        return head.right