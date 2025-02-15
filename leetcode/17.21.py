from typing import List


class Solution:

  def trap(self, height: List[int]) -> int:
    ans = 0
    # 单调递减
    stack = []
    for i, val in enumerate(height):
      while stack and height[stack[-1]] <= val:
        cur = stack.pop()
        if not stack:
          break
        w_ = i - stack[-1] - 1
        h_ = min(height[stack[-1]], val) - height[cur]
        ans += w_ * h_
      stack.append(i)
    return ans

  def trap_(self, height: List[int]) -> int:
    ans = 0
    l, r = 0, len(height) - 1
    lm, rm = 0, 0
    while l < r:
      lm = max(lm, height[l])
      rm = max(rm, height[r])
      if height[l] < height[r]:
        ans += lm - height[l]
        l += 1
      else:
        ans += rm - height[r]
        r -= 1
    return ans
