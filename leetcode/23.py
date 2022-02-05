import queue


# Definition for singly-linked list.
class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Item(object):

    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val


class Solution:

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        cache = queue.PriorityQueue(len(lists))
        sentry = ListNode()
        head = sentry

        for item in lists:
            if item is not None:
                cache.put(Item(item))

        while not cache.empty():
            item = cache.get()
            head.next = item.node
            head = head.next
            if head.next is not None:
                cache.put(Item(head.next))

        return sentry.next
