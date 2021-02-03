#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
  enum { MinSize = 31 };
  vector<int> data;
  vector<int> help;
  int tail;

public:
  /** initialize your data structure here. */
  MinStack() : tail(-1), data(MinSize), help(MinSize) {}

  void push(int x) {
    // 使用辅助数组，记录每一次弹入元素时最小元素，空间换时间
    if (++tail >= data.size()) {
      data.push_back(x);
      help.push_back(x);
    }
    data[tail] = x;
    help[tail] = (tail == 0) ? data[tail] : min(data[tail], help[tail - 1]);
  }

  void pop() {
    if (tail == -1) {
      return;
    }
    tail--;
  }

  int top() {
    if (tail == -1) {
      return -1;
    }
    return data[tail];
  }

  int getMin() {
    if (tail == -1) {
      return -1;
    }
    return help[tail];
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */