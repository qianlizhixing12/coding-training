#include <vector>

using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int l = 0;
    int r = arr.size() - 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
        return mid;
      } else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> arr = {3, 4, 5, 1};
  Solution().peakIndexInMountainArray(arr);
  return 1;
}