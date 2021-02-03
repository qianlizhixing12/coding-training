#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int result = 0;
    int temp = 0;
    for (int num : nums) {
      temp = num == 1 ? temp + 1 : 0;
      result = result > temp ? result : temp;
    }
    return result;
  }
};