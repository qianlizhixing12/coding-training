from typing import List
from collections import defaultdict, Counter


class Solution:

    def countPairs(self, deliciousness: List[int]) -> int:
        """先按排序选择组合，类似两两互相比赛，最后一般重复除以二
        枚举二的幂比相加判断是不是二的幂强，一个要循环(根据n的长度)，一个比较固定(范围有了)
        """
        ans, count, targets = 0, Counter(deliciousness), [pow(2, i) for i in range(22)]

        for num1 in count:
            for target in targets:
                num2 = target - num1
                if num2 in count:
                    if num1 == num2:
                        ans += count[num1] * (count[num2] - 1)
                    else:
                        ans += count[num1] * count[num2]

        ans = ans >> 1

        return ans % 1000000007

    def countPairs1(self, deliciousness: List[int]) -> int:
        """边循环边统计
        位置i和i之前元素组成的结果，不会影响i之后元素与之前元素结合，不会导致重复
        自己一开始，为啥让i和i之后相加计算了呢
        """
        ans, count, targets, n = 0, defaultdict(int), [pow(2, i) for i in range(22)], len(deliciousness)

        for num1 in deliciousness:
            for target in targets:
                num2 = target - num1
                ans += count[num2]
            count[num1] += 1

        return ans % 1000000007
