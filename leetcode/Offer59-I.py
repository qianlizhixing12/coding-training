from typing import List
from collections import deque


class Solution:

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """单调递减队列(存储索引)
        """
        if not nums:
            return []

        ans, q = [], deque(maxlen=k)
        for i in range(len(nums)):
            while q and i - q[0] >= k:
                q.popleft()
            while q and nums[q[-1]] <= nums[i]:
                q.pop()
            q.append(i)
            if i + 1 >= k:
                ans.append(nums[q[0]])

        return ans
