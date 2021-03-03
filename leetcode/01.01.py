class Solution:

    def isUnique(self, astr: str) -> bool:
        cache = set()
        for c in astr:
            if c in cache:
                return False
            cache.add(c)
        return True

    def isUnique1(self, astr: str) -> bool:
        return len(astr) == len(set(astr))

    def isUnique2(self, astr: str) -> bool:
        mask = 0
        for c in astr:
            val = 1 << (ord(c) - ord('a'))
            if mask & val != 0:
                return False
            mask = mask | val
        return True