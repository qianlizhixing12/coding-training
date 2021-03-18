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
        # help结构 源节点 -> List[源节点对应复制节点，源节点对应random节点]
        help = {}
        while head:
            tmp = Node(head.val)
            cur.next = tmp
            help[head] = [tmp, head.random]
            head = head.next
            cur = cur.next
        for node in help:
            help[node][0].random = help[help[node]
                                        [1]][0] if help[node][1] else None
        return dummy.next
