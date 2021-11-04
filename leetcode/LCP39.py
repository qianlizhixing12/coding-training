from typing import List
from collections import Counter


class Solution:

    def minimumSwitchingTimes(self, source: List[List[int]], target: List[List[int]]) -> int:
        source, target = Counter(sum(source, [])), Counter(sum(target, []))
        diff = source - target
        return sum(diff.values())
