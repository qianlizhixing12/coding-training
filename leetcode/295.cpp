#include <queue>

using namespace std;

class MedianFinder {
private:
  priority_queue<int, vector<int>, less<int>> left;
  priority_queue<int, vector<int>, greater<int>> right;

public:
  /** initialize your data structure here. */
  MedianFinder() : left(), right() {}

  void addNum(int num) {
    if (left.size() == right.size()) {
      right.push(num);
      int tmp = right.top();
      right.pop();
      left.push(tmp);
    } else {
      left.push(num);
      int tmp = left.top();
      left.pop();
      right.push(tmp);
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return (left.top() + right.top()) / 2.0;
    } else {
      return left.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */