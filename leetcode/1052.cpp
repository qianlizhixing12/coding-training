#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int sum(vector<int> &customers, vector<int> &grumpy) {
    int rst = 0;
    for (int i = 0; i < customers.size(); ++i) {
      if (grumpy[i] == 0) {
        rst += customers[i];
      }
    }
    return rst;
  }

  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int rst = sum(customers, grumpy);
    // if (X >= customers.size()) {
    //   return rst;
    // }
    for (int i = 0; i < X; ++i) {
      if (grumpy[i] == 1) {
        rst += customers[i];
      }
    }
    int max_ = rst;
    for (int i = 1; i <= customers.size() - X; ++i) {
      rst = rst - (grumpy[i - 1] == 1 ? customers[i - 1] : 0) +
            (grumpy[i + X - 1] == 1 ? customers[i + X - 1] : 0);
      max_ = max(max_, rst);
    }
    return max_;
  }
};

int main() {
  //   vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  //   vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  //   int X = 3;
  vector<int> customers = {3};
  vector<int> grumpy = {1};
  int X = 1;
  Solution().maxSatisfied(customers, grumpy, X);
  return 0;
}