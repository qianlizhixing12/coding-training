#include <vector>
#include <numeric>

using std::accumulate;
using std::max;
using std::vector;

class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> result(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        result[i] = result[i - 1] + 1;
      }
    }
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        result[i] = max(result[i], result[i + 1] + 1);
      }
    }
    return accumulate(result.begin(), result.end(), 0);
  }
};