#include <stdlib.h>
#include <vector>

using std::vector;

class Solution {
public:
  vector<int> sortArray_insertsort1(vector<int> &nums) {
    // 插入排序
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
      int j = i - 1;
      int tmp = nums[i];
      for (; j >= 0; --j) {
        if (nums[j] > tmp) {
          nums[j + 1] = nums[j];
        } else {
          break;
        }
      }
      nums[j + 1] = tmp;
    }
    return nums;
  }

  vector<int> sortArray_insertsort2(vector<int> &nums) {
    // 插入排序
    int len = nums.size();
    for (int i = 1; i < len; ++i) {
      int j = i - 1;
      int tmp = nums[i];
      while (j >= 0 && nums[j] > tmp) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = tmp;
    }
    return nums;
  }

  vector<int> sortArray_bubblesort(vector<int> &nums) {
    // 冒泡排序
    for (int i = nums.size() - 1; i >= 0; --i) {
      bool flag = false;
      for (int j = 0; j <= i - 1; ++j) {
        if (nums[j] > nums[j + 1]) {
          int tmp = nums[j];
          nums[j] = nums[j + 1];
          nums[j + 1] = tmp;
          flag = true;
        }
      }
      if (!flag)
        break;
    }
    return nums;
  }

  vector<int> sortArray_selectsort(vector<int> &nums) {
    // 选择排序
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      int pos = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[pos] > nums[j]) {
          pos = j;
        }
      }
      int tmp = nums[i];
      nums[i] = nums[pos];
      nums[pos] = tmp;
    }

    return nums;
  }

  void mergesort(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int mid = left + ((right - left) >> 1);
    mergesort(nums, left, mid);
    mergesort(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }

  void merge(vector<int> &nums, int left, int mid, int right) {
    int n = right - left + 1;
    int *tmp = (int *)malloc(sizeof(int) * n);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
      tmp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    }

    while (i <= mid) {
      tmp[k++] = nums[i++];
    }

    while (j <= right) {
      tmp[k++] = nums[j++];
    }

    for (k = 0; k < n; ++k) {
      nums[left + k] = tmp[k];
    }

    free(tmp);
  }

  vector<int> sortArray_mergesort(vector<int> &nums) {
    // 归并排序
    int l = 0;
    int r = nums.size() - 1;

    mergesort(nums, l, r);

    return nums;
  }
};