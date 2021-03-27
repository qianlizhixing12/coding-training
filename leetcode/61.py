# Definition for singly-linked list.
class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if k == 0 or head == None or head.next == None:
            return head
        n = 1
        cur = head
        while cur.next != None:
            n += 1
            cur = cur.next
        k = n - k % n
        if k == n:
            return head
        cur.next = head
        while k:
            cur = cur.next
            k -= 1
        ans = cur.next
        cur.next = None
        return ans
