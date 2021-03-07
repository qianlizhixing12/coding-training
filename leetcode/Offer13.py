from typing import Tuple


class Solution:

    def movingCount(self, m: int, n: int, k: int) -> int:
        self.num_sum = {}
        self.dir_vaild = {}
        self.dfs(m, n, k, 0, 0)
        return sum(1 for dir in self.dir_vaild.values() if dir)

    def dfs(self, m: int, n: int, k: int, x: int, y: int):
        if not (0 <= x < m) or not (0 <= y < n) or (x, y) in self.dir_vaild:
            return
        if not self.vaild(k, x, y):
            return
        self.dfs(m, n, k, x - 1, y)
        self.dfs(m, n, k, x + 1, y)
        self.dfs(m, n, k, x, y - 1)
        self.dfs(m, n, k, x, y + 1)

    def vaild(self, k: int, x: int, y: int) -> bool:
        dir = (x, y)
        if dir in self.dir_vaild:
            return self.dir_vaild[dir]
        if x not in self.num_sum:
            self.num_sum[x] = self.get_sum(x)
        if y not in self.num_sum:
            self.num_sum[y] = self.get_sum(y)
        self.dir_vaild[dir] = self.num_sum[x] + self.num_sum[y] <= k
        return self.dir_vaild[dir]

    def get_sum(self, v: int):
        sum_ = 0
        while v != 0:
            sum_ += v % 10
            v //= 10
        return sum_


if __name__ == "__main__":
    print(Solution().movingCount(1, 2, 1))
