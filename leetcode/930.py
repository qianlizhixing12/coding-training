from typing import List
from collections import deque


class Solution:

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        prefix_sum, sliding_window, answer = 0, deque(), 0

        for num in nums:
            sliding_window.append(num)
            prefix_sum += num
            if prefix_sum == goal:
                if sliding_window[0] == 0:
                    answer += 2
                else:
                    answer += 1
            elif prefix_sum > goal:
                prefix_sum -= sliding_window.popleft()
                answer += 2

        return answer


# print(Solution().numSubarraysWithSum(nums=[1, 0, 1, 0, 1], goal=2))
print(Solution().numSubarraysWithSum(nums=[0, 0, 0, 0, 0], goal=0))
