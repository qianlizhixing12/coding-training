from typing import List


class Solution:

    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans, sum, left = [], 1, 1
        for right in range(2, target):
            sum += right
            if sum == target:
                ans.append([i for i in range(left, right + 1)])
            while sum > target:
                sum -= left
                left += 1
                if sum == target:
                    ans.append([i for i in range(left, right + 1)])
        return ans
