# Definition for a binary tree node.
class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):

        def dfs(root):
            if root == None:
                return "#"

            return str(root.val) + "," + dfs(root.left) + "," + dfs(root.right)

        return dfs(root)

    def deserialize(self, data):

        def dfs():
            nonlocal pos
            nonlocal length
            if length == pos + 1:
                return None

            if nodes[pos] == "#":
                return None

            root = TreeNode(int(nodes[pos]))
            pos += 1
            root.left = dfs()
            pos += 1
            root.right = dfs()
            return root

        nodes, pos = data.split(","), 0
        length = len(nodes)
        return dfs()


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))