from typing import List


# Definition for Employee.
class Employee:

    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:

    def getImportance(self, employees: List['Employee'], id: int) -> int:

        def dfs(id: int) -> int:
            if not id in cache:
                return 0

            return cache[id].importance + sum((dfs(sub) for sub in cache[id].subordinates))

        cache = {employee.id: employee for employee in employees}

        return dfs(id)
