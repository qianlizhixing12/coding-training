from typing import List


class Solution:

    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        ans = 1
        cnt = 1
        for i in range(1, len(nums)):
            cnt = cnt + 1 if nums[i] == nums[i - 1] else 1
            if cnt <= 2:
                nums[ans] = nums[i]
                ans += 1
        return ans