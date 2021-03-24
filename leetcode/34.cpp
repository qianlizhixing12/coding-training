#include <vector>

using namespace std;

class Solution {
public:
  /**
   * O(n)
   */
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result = {-1, -1};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] > target) {
        return result;
      }
      if (nums[i] == target) {
        if (result[0] == -1) {
          result[0] = i;
        } else {
          result[1] = i;
        }
      }
    }
    return result;
  }

  /**
   * O(logN)
   */
  vector<int> searchRange_(vector<int> &nums, int target) {
    vector<int> result = {-1, -1};
    binarySearch(nums, 0, nums.size() - 1, target, result);
    return result;
  }

  void binarySearch(vector<int> &nums, int l, int r, int target,
                    vector<int> &result) {
    if (l > r || nums[l] > target || nums[r] < target) {
      return;
    }
    int mid = (l + r) >> 1;
    if (nums[mid] == target) {
      int tmp = mid - 1;
      while (tmp >= l && nums[tmp] == target) {
        tmp--;
      }
      result[0] = tmp + 1;
      tmp = mid + 1;
      while (tmp <= r && nums[tmp] == target) {
        tmp++;
      }
      result[1] = tmp - 1;
    } else if (nums[mid] > target) {
      binarySearch(nums, l, mid - 1, target, result);
    } else {
      binarySearch(nums, mid + 1, r, target, result);
    }
  }

  /**
   * O(logN)
   */
  vector<int> searchRange__(vector<int> &nums, int target) {
    int left = getLeft(nums, target);
    int right = getRight(nums, target);
    return vector<int>(left, right);
  }

  int getLeft(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (l != nums.size() && nums[l] == target) {
      return l;
    }
    return -1;
  }

  int getRight(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (r != -1 && nums[r] == target) {
      return r;
    }
    return -1;
  }
};