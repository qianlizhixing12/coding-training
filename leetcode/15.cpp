#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
      return result;
    }
    // 辅助数组，不改动实参
    vector<int> help(nums.begin(), nums.end());
    // 排序
    sort(help.begin(), help.end());
    // 先固定i,左右双指针left和right在i到size-1之间滚动
    for (int i = 0; i < help.size(); i++) {
      // 全是正数
      if (help[i] > 0) {
        break;
      }
      int left = i + 1;
      int right = help.size() - 1;
      while (left < right) {
        // 全是负数
        if (help[right] < 0) {
          break;
        }
        if (help[i] + help[left] + help[right] == 0) {
          result.push_back(vector<int>({help[i], help[left], help[right]}));
          while (left < right && help[left] == help[left + 1]) {
            left++;
          }
          while (left < right && help[right] == help[right - 1]) {
            right--;
          }
          left++;
          right--;
        } else if (help[i] + help[left] + help[right] < 0) {
          left++;
        } else {
          right--;
        }
      }
      // 去重
      while (i < right && help[i] == help[i + 1]) {
        i++;
      }
    }
    return result;
  }
};

int main() {
  vector<int> temp({3, 0, -2, -1, 1, 2});

  Solution().threeSum(temp);

  return 0;
}