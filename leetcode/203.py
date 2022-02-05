# Definition for singly-linked list.
class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def removeElements(self, head: ListNode, val: int) -> ListNode:
        sentry = ListNode(0, head)
        head = sentry

        while head.next is not None:
            if head.next.val != val:
                head = head.next
            else:
                head.next = head.next.next

        return sentry.next
