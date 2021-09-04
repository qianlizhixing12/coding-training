from typing import List


class Solution:

    def partitionLabels(self, s: str) -> List[int]:
        # 统计最后一次出现位置
        count = {}
        for i, c in enumerate(s):
            count[c] = i

        result, l, r = [], -1, -1
        for i, c in enumerate(s):
            if count[c] > r:
                # 当前字符最后出现位置比右边界大，更新有边界
                r = count[c]
            if r <= i:
                result.append(i - l)
                l = i
        return result
