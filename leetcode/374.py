def guess(num: int) -> int:
    pass


class Solution:

    def guessNumber(self, n: int) -> int:
        left, right = 1, n
        while left <= right:
            mid = (left + right) // 2
            tmp = guess(mid)
            if tmp == 0:
                return mid
            if tmp == 1:
                left = mid + 1
            else:
                right = mid - 1


Solution().guessNumber(1)