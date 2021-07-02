from typing import List


class Solution:

    def maxIceCream(self, costs: List[int], coins: int) -> int:
        ans = 0

        for cost in sorted(costs):
            if coins < cost:
                break
            ans += 1
            coins -= cost

        return ans