from typing import List
import heapq


class Solution:

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[:k]

    def getLeastNumbers_(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        hp = [-num for num in arr[:k]]
        heapq.heapify(hp)
        for num in arr[k:]:
            if num < -hp[0]:
                heapq.heappop(hp)
                heapq.heappush(hp, -num)
        hp = [-num for num in hp]
        return hp

    def getLeastNumbers__(self, arr: List[int], k: int) -> List[int]:

        def quickSort(arr: List[int], l: int, r: int, k: int):
            if l >= r:
                return
            pos = partition(arr, l, r)
            if pos == k:
                return
            if pos < k:
                quickSort(arr, pos + 1, r, k)
            else:
                quickSort(arr, l, pos - 1, k)

        def partition(arr: List[int], l: int, r: int) -> int:
            count = l
            for i in range(l, r):
                if arr[r] > arr[i]:
                    arr[count], arr[i] = arr[i], arr[count]
                    count += 1
            arr[count], arr[r] = arr[r], arr[count]
            return count

        if k == 0:
            return []
        quickSort(arr, 0, len(arr) - 1, k - 1)
        return arr[:k]


if __name__ == "__main__":
    Solution().getLeastNumbers_([3, 2, 1], 2)