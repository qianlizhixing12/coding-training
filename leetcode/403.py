from typing import List
from collections import defaultdict


class Solution:

    def canCross(self, stones: List[int]) -> bool:
        """暴力解法
        """

        def dfs(stones: List[int], pos: int, step: int) -> bool:
            if pos == len(stones) - 1:
                return True
            steps = [i + step for i in (-1, 0, 1) if i + step > 0]
            for step in steps:
                for cur in range(pos + 1, len(stones)):
                    if stones[pos] + step < stones[cur]:
                        break
                    if stones[pos] + step == stones[cur] and dfs(stones, cur, step):
                        return True
            return False

        # stones[0] = 0, 第一步只能跳1
        if stones[1] != 1:
            return False

        return dfs(stones, 1, 1)

    def canCross_(self, stones: List[int]) -> bool:
        """缓存备忘录
        """

        def dfs(stones: List[int], pos: int, step: int) -> bool:
            if pos == len(stones) - 1:
                return True
            if (pos, step) in cache:
                return cache[(pos, step)]
            steps = [i + step for i in (-1, 0, 1) if i + step > 0]
            for step_ in steps:
                for cur in range(pos + 1, len(stones)):
                    if stones[pos] + step_ < stones[cur]:
                        break
                    if stones[pos] + step_ == stones[cur] and dfs(stones, cur, step_):
                        cache[(pos, step)] = True
                        return True
            cache[(pos, step)] = False
            return False

        # stones[0] = 0, 第一步只能跳1
        if stones[1] != 1:
            return False

        cache = {}

        return dfs(stones, 1, 1)

    def canCross__(self, stones: List[int]) -> bool:
        """动态规划
        """

        # stones[0] = 0, 第一步只能跳1
        if stones[1] != 1:
            return False

        dp = {1: (set(1, 2), 2)}
        r = len(stones)

        for i in range(1, r):
            if not i in dp:
                continue
            steps, max_ = dp[i]
            for j in range(i + 1, r):
                step = stones[j] - stones[i]
                if step > max_:
                    break
                if not step in steps:
                    continue
                if not j in dp:
                    dp[j] = (set(), 0)
                if step > 1:
                    dp[j][0].add(step - 1)
                dp[j][0].add(step)
                dp[j][0].add(step + 1)
                dp[j][1] = max(dp[j][1], step + 1)

        return (r - 1) in dp

    def canCross___(self, stones: List[int]) -> bool:
        """动态规划，增加可读性
        """

        # stones[0] = 0, 第一步只能跳1
        if stones[1] != 1:
            return False

        # 记录第i步对应下一次跳跃可选值
        dp = defaultdict(set)
        dp[1] = {1, 2}
        # 记录第i步对应下一次跳跃最大值
        dpm = defaultdict(int)
        dpm[1] = 2
        r = len(stones)

        for i in range(1, r):
            if not i in dpm:
                continue
            for j in range(i + 1, r):
                step = stones[j] - stones[i]
                if step > dpm[i]:
                    break
                if not step in dp[i]:
                    continue
                if step > 1:
                    dp[j].add(step - 1)
                dp[j].add(step)
                dp[j].add(step + 1)
                dpm[j] = max(dpm[j], step + 1)

        return (r - 1) in dp
