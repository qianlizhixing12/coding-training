#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class LRUCache {
private:
  int capacity_ = 0;
  int size_ = 0;
  unordered_map<int, int> data;
  unordered_map<int, int> cache;

public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    size_ = 0;
    data.clear();
    cache.clear();
  }

  int get(int key) {
    if (cache.count(key) == 0) {
      return -1;
    }
    cache[key]++;
    return data[key];
  }

  void put(int key, int value) {
    if (size_ = capacity_ && cache.count(key) == 0) {
    }
    cache[key]++;
    data[key] = value;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */