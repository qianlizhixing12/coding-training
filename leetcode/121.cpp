#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min_ = INT_MAX;
    int rst = 0;
    for (int i = 0; i < prices.size(); ++i) {
      min_ = min(min_, prices[i]);
      if (prices[i] > min_) {
        rst = max(rst, prices[i] - min_);
      }
    }
    return rst;
  }
};