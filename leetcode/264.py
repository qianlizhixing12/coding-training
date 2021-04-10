class Solution:

    def nthUglyNumber(self, n: int) -> int:
        data = [1] * n
        m1 = m2 = m3 = 0
        for i in range(1, n):
            v1, v2, v3 = data[m1] * 2, data[m2] * 3, data[m3] * 5
            data[i] = min(v1, v2, v3)
            if data[i] == v1:
                m1 += 1
            if data[i] == v2:
                m2 += 1
            if data[i] == v3:
                m3 += 1
        return data[-1]


if __name__ == "__main__":
    Solution().nthUglyNumber(10)
    Solution().nthUglyNumber(11)