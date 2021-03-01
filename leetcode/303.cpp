#include <vector>

using namespace std;

class NumArray1 {
private:
  vector<int> data;

public:
  // 暴力
  NumArray1(vector<int> &nums) { data = vector<int>(nums.begin(), nums.end()); }

  int sumRange(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
      sum += data[k];
    }
    return sum;
  }
};

class NumArray {
private:
  vector<int> data;

public:
  // 暴力
  NumArray(vector<int> &nums) {
    data = vector<int>(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      data[i + 1] = data[i] + nums[i];
    }
  }

  int sumRange(int i, int j) { return data[j + 1] - data[i]; }
};