#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  // Boyer-Moore Majority Vote 摩尔投票法
  int majorityElement(vector<int> &nums) {
    int result = 0;
    int count = 0;
    for (int num : nums) {
      // 根据定义，多数元素是指在数组中出现次数大于⌊n/2⌋的元素，即能抵消其他所有人票的总和
      if (count == 0 || num == result) {
        count++;
        result = num;
      } else {
        count--;
      }
    }
    return result;
  }

  // 哈系方法记录出现次数
  int majorityElementByHash(vector<int> &nums) {
    // 哈系表 数值->次数
    unordered_map<int, int> help;
    // ⌊n/2⌋ + 1
    int major = (nums.size() >> 1) + 1;
    for (int num : nums) {
      // if (counts.find(num) == counts.end()) {
      if (help.count(num) > 0) {
        help[num]++;
      } else {
        help[num] = 1;
      }
      if (help[num] >= major) {
        // 次数大于⌊n/2⌋
        return num;
      }
    }
  }
};