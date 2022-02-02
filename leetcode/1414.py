class Solution:

    def findMinFibonacciNumbers(self, k: int) -> int:
        arr = [1, 1]
        while arr[-1] + arr[-2] <= k:
            arr.append(arr[-1] + arr[-2])

        count, pos = 0, len(arr) - 1

        while pos >= 0 and k > 0:
            if arr[pos] <= k:
                count += 1
                k = k - arr[pos]
            else:
                pos -= 1

        return count