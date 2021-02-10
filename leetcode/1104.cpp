#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> pathInZigZagTree(int label) {
    vector<int> ans;
    // labal所处行数
    int level = log2(label);
    while (label > 1) {
      ans.push_back(label);
      label = 3 * (1 << (--level)) - (label >> 1) - 1;
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  vector<int> ans = Solution().pathInZigZagTree(26);
  for_each(ans.begin(), ans.end(), [](int val) { cout << val << " "; });
  cout << endl;
  return 0;
}