# Definition for singly-linked list.
from typing import List


class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sentry = ListNode()
        head = sentry
        value = 0

        while l1 is not None or l2 is not None:
            if l1 is not None:
                value += l1.val
                l1 = l1.next

            if l2 is not None:
                value += l2.val
                l2 = l2.next

            head.next = ListNode(value % 10)
            head = head.next
            value = value // 10

        if value != 0:
            head.next = ListNode(value % 10)

        return sentry.next
