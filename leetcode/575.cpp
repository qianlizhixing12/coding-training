#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int distributeCandies(vector<int> &candyType) {
    sort(candyType.begin(), candyType.end());
    int count = 1;
    int pos = 1;
    int len = candyType.size();
    int max = len >> 1;
    while (pos < len && count < max) {
      if (candyType[pos] != candyType[pos - 1]) {
        count++;
      }
      pos++;
    }
    return count;
  }
};