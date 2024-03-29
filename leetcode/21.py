# Definition for singly-linked list.
from configparser import SectionProxy


class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        sentry = ListNode()
        head = sentry

        while list1 is not None and list2 is not None:
            if list1.val <= list2.val:
                head.next = list1
                list1 = list1.next
            else:
                head.next = list2
                list2 = list2.next

            head = head.next

        head.next = list1 if list1 is not None else list2

        return sentry.next
