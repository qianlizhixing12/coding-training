from typing import List


class Solution:

    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        rst, x, y, opt = 0, 0, 0, 0
        # 向北走,向东走, 向南走, 向西走
        opts = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        obstacles = set(map(tuple, obstacles))
        for cmd in commands:
            if cmd < 0:
                # 向右转
                if cmd == -1:
                    opt = (opt + 1) % 4
                # 向左转
                elif cmd == -2:
                    opt = (opt + 4 - 1) % 4
            else:
                # 向前一步步试探
                for step in range(cmd):
                    x1, y1 = x + opts[opt][0], y + opts[opt][1]
                    if (x1, y1) not in obstacles:
                        x, y = x1, y1
                        rst = max(rst, x * x + y * y)
        return rst
