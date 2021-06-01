from typing import List
from functools import accumulate


class Solution:

    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        ans, count = [], list(accumulate(candiesCount))
        for query in queries:
            # 从第0天开始
            day = query[1] + 1
            # 到当天共有糖果
            count_r = count[query[0]]
            # 前一天共有糖果(第0天前一天边界处理)
            count_l = 0 if query[0] == 0 else count[query[0] - 1]
            # 两个条件（按最多量吃，前一天必须吃完；每天吃一颗，必须能到今天）
            ans.append(count_l < day * query[2] and count_r >= day)
        return ans
