#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= nums2[i]) {
        s.pop();
      }
      m[nums2[i]] = s.empty() ? -1 : s.top();
      s.push(nums2[i]);
    }
    vector<int> rst;
    for (int v : nums1) {
      rst.emplace_back(m[v]);
    }
    return rst;
  }

  vector<int> nextGreaterElement_(vector<int> &nums1, vector<int> &nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    int n = nums2.size();
    for (int i = 0; i < n; i++) {
      while (!s.empty() && nums2[s.top()] < nums2[i]) {
        m[nums2[s.top()]] = nums2[i];
        s.pop();
      }
      s.push(i);
    }
    vector<int> rst;
    for (int v : nums1) {
      rst.emplace_back(m.count(v) > 0 ? m[v] : -1);
    }
    return rst;
  }
};