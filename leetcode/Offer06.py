from typing import List


# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def reversePrint(self, head: ListNode) -> List[int]:
        rst = []
        while head != None:
            rst.append(head.val)
            head = head.next
        # rst.reverse()
        # return rst
        return rst[::-1]