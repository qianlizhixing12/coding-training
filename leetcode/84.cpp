#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> s;
    int rst = 0;
    // 处理边界
    heights.emplace(heights.begin(), 0);
    heights.emplace_back(0);
    int n = heights.size();
    for (int i = 0; i < n; i++) {
      while (!s.empty() && heights[s.top()] > heights[i]) {
        int id = s.top();
        s.pop();
        int left = s.top() + 1;
        rst = max(rst, (i - left + 1) * heights[id]);
      }
      s.push(i);
    }
    return rst;
  }
};