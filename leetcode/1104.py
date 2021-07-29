from typing import List


class Solution:

    def pathInZigZagTree(self, label: int) -> List[int]:
        tree, num, level = [], 0, 0

        while num < label:
            nums = pow(2, level)
            if level % 2 == 0:
                for i in range(num + 1, num + nums + 1, 1):
                    tree.append(i)
                    if i == label:
                        break
            else:
                for i in range(num + nums, num, -1):
                    tree.append(i)
                    if i == label:
                        break
            num += nums
            level += 1

        ans, index = [], len(tree) - 1
        while index > 0:
            ans.append(tree[index])
            index = (index - 1) >> 1
        ans.append(1)
        ans.reverse()
        return ans
