# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast, cycle = head, head, False

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                cycle = True
                break

        if not cycle:
            return None

        fast = head
        while not fast is slow:
            slow = slow.next
            fast = fast.next
        return fast
