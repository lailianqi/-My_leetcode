#include <list>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
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
namespace ff {
// 自己的改写版 成功ac
class LRUCache {
  private:
    list<pair<int, int>> cacheList;
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    void visit_node(
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it) {
        pair<int, int> temp = *(it->second);
        cacheList.erase(it->second);
        cacheList.push_front(temp);
        it->second = cacheList.begin();
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        visit_node(it);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            visit_node(it);
        } else {
            if (cache.size() == capacity) {
                cache.erase(cacheList.back().first);
                cacheList.pop_back();
            }
            cacheList.push_front({key, value});
        }
        auto it_temp = cacheList.begin();
        it_temp->first = key, it_temp->second = value;
        cache[key] = it_temp;
    }
};
}; // namespace ff

// 二刷
class LRUCache {
  public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        auto it = dir.find(key);
        if (it == dir.end()) {
            return -1;
        }
        visit(it);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = dir.find(key);
        if (it != dir.end()) {
            visit(it);
        } else {
            if (cacheList.size() >= this->capacity) {
                dir.erase(cacheList.back().first);
                cacheList.pop_back();
            }
            cacheList.push_front(make_pair(key, value));
        }
        auto it2 = cacheList.begin();
        it2->second = value;
        dir[it2->first] = it2;
    }

  private:
    void
    visit(unordered_map<int, list<pair<int, int>>::iterator>::iterator it) {
        auto p = *(it->second);
        cacheList.push_front(p);
        cacheList.erase(it->second);
        it->second = cacheList.begin();
    }
    unordered_map<int, list<pair<int, int>>::iterator> dir;
    list<pair<int, int>> cacheList;
    int capacity;
};