#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int rst = 0;
    int cur = INT_MIN;
    // 0待买入 1待售出
    int state = 0;
    for (int i = 0; i < prices.size(); ++i) {
      if (state == 0) {
        if (i != prices.size() - 1 && prices[i] >= prices[i + 1]) {
          continue;
        }
        cur = prices[i];
        state = 1;
      } else {
        if (prices[i] > cur) {
          if (i != prices.size() - 1 && prices[i] < prices[i + 1]) {
            continue;
          }
          rst += prices[i] - cur;
          state = 0;
        }
      }
    }
    return rst;
  }
};