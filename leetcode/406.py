from typing import List


class Solution:

    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda elem: (-elem[0], elem[1]))
        ans = []
        for p in people:
            if len(ans) <= p[1]:
                ans.append(p)
            else:
                ans.insert(p[1], p)
        return ans
