from typing import List
from sortedcontainers import SortedList
import bisect


class Solution:

    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int,
                                      t: int) -> bool:
        if not nums:
            return False
        od = SortedList()
        for i in range(len(nums)):
            # 保持k个元素
            if i > k:
                od.remove(nums[i - k - 1])
            od.add(nums[i])
            index = bisect.bisect_left(od, nums[i])
            if index > 0 and od[index] - od[index - 1] <= t:
                return True
            if index < len(od) - 1 and od[index + 1] - od[index] <= t:
                return True
        return False