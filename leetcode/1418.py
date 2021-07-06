from typing import List
from collections import defaultdict


class Solution:

    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        count, tables, foods = {}, set(), set()
        for _, table, food in orders:
            tables.add(table)
            foods.add(food)
            if food not in count:
                count[food] = defaultdict(int)
            count[food][table] += 1

        tables, foods, ans = sorted(tables, key=lambda table: int(table)), sorted(foods), [["Table"] * (len(foods) + 1) for _ in range(len(tables) + 1)]
        for i, food in enumerate(foods):
            ans[0][i + 1] = food
            for j, table in enumerate(tables):
                ans[j + 1][0] = table
                ans[j + 1][i + 1] = str(count[food][table])
        return ans
