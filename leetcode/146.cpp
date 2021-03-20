#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
  struct Node {
    int key;
    int val;
    Node *pre;
    Node *next;
    Node(int key, int val, Node *pre, Node *next)
        : key(key), val(val), pre(pre), next(next) {}
  };
  int capacity = 0;
  int size = 0;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> cache;

public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new Node(0, 0, nullptr, nullptr);
    tail = new Node(0, 0, head, nullptr);
    head->next = tail;
    cache.clear();
  }

  int get(int key) {
    if (cache.count(key) == 0) {
      return -1;
    }
    Node *node = cache[key];
    // 移除node
    Node *pre = node->pre;
    Node *next = node->next;
    pre->next = next;
    next->pre = pre;
    // 添加头部node
    node->next = head->next;
    head->next->pre = node;
    head->next = node;
    node->pre = head;
    return node->val;
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      head->next->val = value;
    } else {
      // 添加头部node
      Node *node = new Node(key, value, head, head->next);
      cache[key] = node;
      head->next->pre = node;
      head->next = node;
      if (size == capacity) {
        //删除尾部
        Node *pre = tail->pre->pre;
        cache.erase(tail->pre->key);
        delete tail->pre;
        pre->next = tail;
        tail->pre = pre;
      } else {
        size++;
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  cout << lru.get(1) << endl;
  lru.put(3, 3);
  cout << lru.get(2) << endl;
  lru.put(4, 4);
  cout << lru.get(1) << endl;
  cout << lru.get(3) << endl;
  cout << lru.get(4) << endl;
  return 0;
}