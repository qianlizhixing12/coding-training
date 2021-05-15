class Solution:
    def romanToInt(self, s: str) -> int:
        signs = {"M": 1000, "CM": 900, "D": 500, "CD": 400, "C": 100, "XC": 90, "L": 50,
                 "XL": 40, "X": 10, "IX": 9, "V": 5, "IV": 4, "I": 1}
        num = 0
        n = len(s)
        pos = 0

        while pos < n:
            if s[pos:pos + 2] in signs:
                num += signs[s[pos:pos + 2]]
                pos += 2
            else:
                num += signs[s[pos:pos + 1]]
                pos += 1

        return num
