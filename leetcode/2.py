# Definition for singly-linked list.
class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = result = ListNode()
        tmp = 0

        while l1 and l2:
            cur.next = ListNode(l1.val + l2.val + tmp)
            cur = cur.next
            tmp = cur.val // 10
            cur.val = cur.val % 10
            l1 = l1.next
            l2 = l2.next

        while l1:
            cur.next = ListNode(l1.val + tmp)
            cur = cur.next
            tmp = cur.val // 10
            cur.val = cur.val % 10
            l1 = l1.next

        while l2:
            cur.next = ListNode(l2.val + tmp)
            cur = cur.next
            tmp = cur.val // 10
            cur.val = cur.val % 10
            l2 = l2.next

        if tmp == 1:
            cur.next = ListNode(tmp)

        return result.next
