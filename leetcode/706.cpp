#include <vector>

using namespace std;

class MyHashMap {
private:
  static const int cap = 100001;
  vector<int> data;

public:
  /** Initialize your data structure here. */
  MyHashMap() : data(cap, -1) {}

  /** value will always be non-negative. */
  void put(int key, int value) { data[key % cap] = value; }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) { return data[key % cap]; }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) { data[key % cap] = -1; }
};

class MyHashMap {
private:
  static const int cap = 997;
  vector<vector<pair<int, int>>> data;

public:
  /** Initialize your data structure here. */
  MyHashMap() : data(cap) {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    int h = key % cap;
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if (it->first == key) {
        it->second = value;
        return;
      }
    }
    data[h].emplace_back(key, value);
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    int h = key % cap;
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if (it->first == key) {
        return it->second;
      }
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    int h = key % cap;
    for (auto it = data[h].begin(); it != data[h].end(); it++) {
      if (it->first == key) {
        data[h].erase(it);
        return;
      }
    }
  }
};