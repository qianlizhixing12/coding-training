#include <stack>

using namespace std;

class CQueue {
private:
  stack<int> in;
  stack<int> out;

  void carry() {
    int n = in.size();
    while (n-- > 0) {
      out.push(in.top());
      in.pop();
    }
  }

public:
  CQueue() {
    in = stack<int>();
    out = stack<int>();
  }

  void appendTail(int value) { in.push(value); }

  bool empty() { return in.empty() && out.empty(); }

  int deleteHead() {
    if (empty()) {
      return -1;
    }
    if (out.size() == 0) {
      carry();
    }
    int value = out.top();
    out.pop();
    return value;
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */