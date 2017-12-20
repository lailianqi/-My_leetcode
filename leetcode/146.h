#include <list>
#include <map>
#include <unordered_map>
#include <vector>
// https://discuss.leetcode.com/topic/6812/c-11-code-74ms-hash-table-list?page=1
class LRUCache {
  private:
    list<int> cacheList;
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    void
    touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        cacheList.erase(it->second.second);
        cacheList.push_front(key);
        it->second.second = cacheList.begin();
    }

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end())
            touch(it);
        else {
            if (cache.size() == capacity) {
                cache.erase(cacheList.back());
                cacheList.pop_back();
            }
            cacheList.push_front(key);
        }
        cache[key] = {value, cacheList.begin()};
    }
};