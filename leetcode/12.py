class Solution:
    def intToRoman(self, num: int) -> str:
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        sign = ["M", "CM", "D", "CD", "C", "XC", "L",
                "XL", "X", "IX", "V", "IV", "I"]

        ans = ""
        pos = 0

        while num != 0:
            if num >= nums[pos]:
                ans += sign[pos] * (num // nums[pos])
                num %= nums[pos]
            pos += 1

        return ans
