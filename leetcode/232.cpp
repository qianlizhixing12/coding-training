#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> in;
  stack<int> out;
  void carry() {
    int n = in.size();
    for (int i = 0; i < n; ++i) {
      out.push(in.top());
      in.pop();
    }
  }

public:
  /** Initialize your data structure here. */
  MyQueue() {
    in = stack<int>();
    out = stack<int>();
  }

  /** Push element x to the back of queue. */
  void push(int x) { in.push(x); }

  /** Removes the element from in front of queue and returns that element.
   */
  int pop() {
    int rst = peek();
    out.pop();
    return rst;
  }

  /** Get the front element. */
  int peek() {
    if (out.size() == 0) {
      carry();
    }
    return out.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return in.empty() && out.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */