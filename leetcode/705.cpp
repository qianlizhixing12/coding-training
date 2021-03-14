#include <vector>

using namespace std;

/**
 * 超大空间，不会产生冲突
 */
class MyHashSet {
private:
  int cap = 100001;
  vector<bool> data;

public:
  /** Initialize your data structure here. */
  MyHashSet() { data = vector<bool>(cap, false); }

  void add(int key) { data[key] = true; }

  void remove(int key) { data[key] = false; }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return data[key]; }
};

/**
 * 链表法解决冲突
 */
class MyHashSet1 {
private:
  static const int cap = 997;
  vector<vector<int>> data;

public:
  /** Initialize your data structure here. */
  MyHashSet1() : data(cap) {}

  void add(int key) {
    int h = key % cap;
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if (*it == key) {
        return;
      }
    }
    data[h].emplace_back(key);
  }

  void remove(int key) {
    int h = key % cap;
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if (*it == key) {
        data[h].erase(it);
        return;
      }
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int h = key % cap;
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if (*it == key) {
        return true;
      }
    }
    return false;
  }
};