#include <vector>
#include <numeric>

using std::accumulate;
using std::max;
using std::vector;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> result(n, 1);

    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        result[i] = result[i - 1] + 1;
      }
    }

    int ans = result[n - 1];
    for (int i = n - 2; i > -1; --i) {
      if (ratings[i] > ratings[i + 1]) {
        result[i] = max(result[i], result[i + 1] + 1);
      }
      ans += result[i];
    }

    // return accumulate(result.begin(), result.end(), 0);
    return ans;
  }
};