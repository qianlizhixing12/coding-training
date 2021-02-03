#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int result = 0;
    if (height.size() == 0) {
      return result;
    }

    vector<int> max_left(height.size());
    vector<int> max_right(height.size());

    max_left[0] = height[0];
    for (int i = 1; i < height.size(); i++) {
      max_left[i] = max(max_left[i - 1], height[i]);
    }
    max_right[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; i--) {
      max_right[i] = max(max_right[i + 1], height[i]);
    }

    for (int i = 1; i < height.size() - 1; i++) {
      result += min(max_left[i], max_right[i]) - height[i];
    }

    return result;
  }

  // 优化
  int trapfinal(vector<int> &height) {
    int result = 0;
    if (height.size() == 0) {
      return result;
    }

    int left = 0;
    int right = height.size() - 1;
    int max_left = 0;
    int max_right = 0;

    while (left < right) {
      if (height[left] < height[right]) {
        if (max_left <= height[left]) {
          max_left = height[left];
        } else {
          result += max_left - height[left];
        }
        left++;
      } else {
        if (max_right <= height[right]) {
          max_right = height[right];
        } else {
          result += max_right - height[right];
        }
        right--;
      }
    }

    return result;
  }
};