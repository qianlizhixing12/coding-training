class Solution:

    def isPerfectSquare(self, num: int) -> bool:
        """二分查找
        """
        l, r = 0, num
        while l <= r:
            mid = l + (r - l) // 2
            tmp = mid * mid
            if tmp == num:
                return True
            if tmp > num:
                r = mid - 1
            else:
                l = mid + 1
        return False