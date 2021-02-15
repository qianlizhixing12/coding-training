#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    unordered_map<char, vector<int>> cache;
    for (int i = 0; i < A.size(); i++) {
      for (char c : A[i]) {
        if (cache.count(c) == 0) {
          cache[c] = vector<int>(A.size(), 0);
        }
        cache[c][i]++;
      }
    }
    vector<string> ans;
    for (pair<char, vector<int>> it : cache) {
      for (int i = 0; i < *min_element(it.second.begin(), it.second.end());
           i++) {
        ans.emplace_back(string(1, it.first));
      }
    }
    return ans;
  }
};

int main() {
  vector<string> A = {"bella", "label", "roller"};
  Solution().commonChars(A);
  return 0;
}