# Definition for singly-linked list.
from pickle import LIST


class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def swapPairs(self, head: ListNode) -> ListNode:
        sentry = ListNode(0, head)
        head = sentry

        while head.next is not None and head.next.next is not None:
            tmp1 = head.next
            tmp2 = head.next.next
            head.next = tmp2
            tmp1.next = tmp2.next
            tmp2.next = tmp1
            head = tmp1

        return sentry.next


if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    print(Solution().swapPairs(head))