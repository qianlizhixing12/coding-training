#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> result(digits.rbegin(), digits.rend());

    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
      if (*it < 9) {
        (*it)++;
        break;
      }
      *it = 0;
    }

    for (int num : digits) {
      if (num != 0) {
        // 除了整数0之外，这个整数不会以零开头
        if (result[result.size() - 1] == 0) {
          result.push_back(1);
        }
        break;
      }
    }

    return vector<int>(result.rbegin(), result.rend());
  }
};