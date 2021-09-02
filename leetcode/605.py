class Solution:

    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        l = len(flowerbed) - 1
        for i, place in enumerate(flowerbed):
            if place == 1:
                continue
            if i > 0 and flowerbed[i - 1] == 1:
                continue
            if i < l and flowerbed[i + 1] == 1:
                continue
            n -= 1
            flowerbed[i] = 1
        return n <= 0