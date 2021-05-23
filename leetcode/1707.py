from typing import List
import bisect


class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        # 排序
        nums_tmp = sorted(nums)
        # 去重
        nums_copy = [nums_tmp[0]]
        for num in nums_tmp:
            if num != nums_copy[-1]:
                nums_copy.append(num)
        ans, n, cache = [], len(nums_copy), {}
        # 二分查找
        for query in queries:
            res = -1
            if query[1] < nums_copy[0]:
                pos = 0
            elif query[1] > nums_copy[-1]:
                pos = n
            elif query[1] in cache:
                pos = cache[query[1]]
            else:
                pos = bisect.bisect_right(nums_copy, query[1])
                cache[query[1]] = pos
            for i in range(pos):
                res = max(res, query[0] ^ nums_copy[i])
            ans.append(res)
        return ans

    def maximizeXor_(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        class Trie(object):
            def __init__(self):
                self.left = None
                self.right = None
                self.min_value = float("inf")

            def insert(self, val: int):
                node = self
                node.min_value = min(node.min_value, val)
                for i in range(30, -1, -1):
                    bit = (val >> i) & 1
                    if bit == 0:
                        if not node.left:
                            node.left = Trie()
                        node = node.left
                    else:
                        if not node.right:
                            node.right = Trie()
                        node = node.right
                    node.min_value = min(node.min_value, val)

            def get_max_xor_with_limit(self, val: int, limit: int):
                node = self
                if node.min_value > limit:
                    return -1

                ans = 0
                for i in range(30, -1, -1):
                    bit = (val >> i) & 1
                    check = False
                    if bit == 0:
                        if node.right and node.right.min_value <= limit:
                            node = node.right
                            check = True
                        else:
                            node = node.left
                    else:
                        if node.left and node.left.min_value <= limit:
                            node = node.left
                            check = True
                        else:
                            node = node.right
                    if check:
                        ans |= 1 << i
                return ans

        root = Trie()
        # 建立字典树
        for num in nums:
            root.insert(num)

        res = [0] * len(queries)
        for i, (x, m) in enumerate(queries):
            res[i] = root.get_max_xor_with_limit(x, m)
        return res


if __name__ == "__main__":
    # Solution().maximizeXor(nums=[0, 1, 2, 3, 4], queries=[[3, 1], [1, 3], [5, 6]])
    Solution().maximizeXor_([5, 2, 4, 6, 6, 3], [[12, 4], [8, 1], [6, 3]])
    # Solution().maximizeXor([536870912, 0, 534710168, 330218644, 142254206],
    #                        [[558240772, 1000000000], [307628050, 1000000000], [3319300, 1000000000],
    #                         [2751604, 683297522], [214004, 404207941]])
