# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast = head
        for _ in range(k):
            if fast != None:
                fast = fast.next
        while fast != None:
            fast = fast.next
            head = head.next
        return head
