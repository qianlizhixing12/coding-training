# Definition for singly-linked list.
class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def removeElements(self, head: ListNode, val: int) -> ListNode:
        while head and head.val == val:
            head = head.next

        if not head:
            return head

        res = head

        while head.next:
            if head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next

        return res
