# Definition for a Node.
class Node:

    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:

    def copyRandomList(self, head: 'Node') -> 'Node':
        dummy = Node(0)
        cur = dummy
        # help结构 源节点 -> 对应复制节点
        help = {}
        while head:
            tmp = Node(head.val)
            cur.next = tmp
            help[head] = tmp
            head = head.next
            cur = cur.next
        for node in help:
            if node.random:
                help[node].random = help[node.random]
        return dummy.next
