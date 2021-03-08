# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        help = ListNode(0)
        help.next = head
        pre = help
        while head != None:
            if head.val == val:
                pre.next = head.next
                break
            head = head.next
            pre = pre.next
        return help.next