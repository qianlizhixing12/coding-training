from typing import List


class Solution:

    def verifyPostorder(self, postorder: List[int]) -> bool:

        def recur(postorder: List[int], l: int, r: int) -> bool:
            if l >= r:
                return True
            m = l
            while m < r and postorder[m] < postorder[r]:
                m += 1
            tmp = m
            while tmp < r:
                if postorder[tmp] < postorder[r]:
                    return False
                tmp += 1
            return recur(postorder, l, m - 1) and recur(postorder, m, r - 1)
