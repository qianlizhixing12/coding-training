from collections import defaultdict


class Solution:

    def countOfAtoms(self, formula: str) -> str:
        count = defaultdict(int)
        while formula != "":
            l, r, atom, num = formula.rfind("("), formula.find(")"), "", 1
            for c in formula[l + 1:r - l]:
                if c.isdigit():
                    if num == 1:
                        num = int(c)
                    else:
                        num = num * 10 + int(c)
                else:
                    if num != 1:
                        count[atom] += num
                        atom = ""
                        num = 1
                    atom += c
