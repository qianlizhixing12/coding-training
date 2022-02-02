# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        result = None
        tmp = None

        while head is not None:
            tmp = head.next
            head.next = result
            result = head
            head = tmp
        
        return result