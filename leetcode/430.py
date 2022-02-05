# Definition for a Node.
from http.client import NON_AUTHORITATIVE_INFORMATION


class Node:

    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:

    def flatten(self, head: 'Node') -> 'Node':

        def dfs(head):
            if head is None:
                return None
            elif head.child is None and head.next is None:
                return head

            if head.child is None:
                return dfs(head.next)
            elif head.next is None:
                head.next = head.child
                head.next.prev = head
                head.child = None
                return dfs(head.next)
            else:
                child = head.child
                next = head.next
                head.child = None
                head.next = child
                child.prev = head
                last = dfs(child)
                last.next = next
                next.prev = last
                return dfs(last)

        dfs(head)

        return head