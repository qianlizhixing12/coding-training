#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
  int *data;
  int capacity;
  int head;
  int tail;

public:
  /** Initialize your data structure here. Set the size of the deque to be k.
   */
  MyCircularDeque(int k) : capacity(k + 1), head(0), tail(0) {
    // 为了处理临界条件，当isfull时，实际size比capacity小1
    data = new int[k + 1];
  }

  ~MyCircularDeque() { delete[] data; }

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }
    data[head = ((head - 1 + capacity) % capacity)] = value;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }
    data[tail] = value;
    tail = (tail + 1 + capacity) % capacity;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }
    head = (head + 1 + capacity) % capacity;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    tail = (tail - 1 + capacity) % capacity;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return data[head];
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return data[(tail - 1 + capacity) % capacity];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() { return head == tail; }

  /** Checks whether the circular deque is full or not. */
  bool isFull() { return head == (tail + 1) % capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
  cout.setf(ios_base::boolalpha);
  MyCircularDeque solution(3);
  cout << solution.insertFront(9) << endl;
  cout << solution.getRear() << endl;
  cout << solution.insertFront(9) << endl;
  cout << solution.getRear() << endl;
  cout << solution.insertLast(5) << endl;
  cout << solution.getFront() << endl;
  cout << solution.getRear() << endl;
  cout << solution.getFront() << endl;
  cout << solution.insertLast(8) << endl;
  cout << solution.deleteLast() << endl;
  cout << solution.getFront() << endl;
  return 0;
}