from typing import List


class Solution:

    def readBinaryWatch_(self, turnedOn: int) -> List[str]:

        def backtrack(count, index):
            if count > turnedOn or time[0] > 11 or time[1] > 59:
                return

            if index == 10:
                if count == turnedOn:
                    s = str(time[0]) + ":"
                    s += str(time[1]) if time[1] > 9 else "0" + str(time[1])
                    ans.append(s)
                return

            # 不选
            backtrack(count, index + 1)
            # 选择
            time[m[index][1]] += m[index][0]
            backtrack(count + 1, index + 1)
            time[m[index][1]] -= m[index][0]

        # hour, minute
        ans, time, m = [], [0, 0], [[8, 0], [4, 0], [2, 0], [1, 0], [32, 1], [16, 1], [8, 1], [4, 1], [2, 1], [1, 1]]
        backtrack(0, 0)
        return ans

    def readBinaryWatch(self, turnedOn: int) -> List[str]:

        def count(num):
            return bin(num).count("1")

        ans = []
        for hour in range(12):
            for minute in range(60):
                if count(hour) + count(minute) == turnedOn:
                    s = str(hour) + ":"
                    s += str(minute) if minute > 9 else "0" + str(minute)
                    ans.append(s)
        return ans
