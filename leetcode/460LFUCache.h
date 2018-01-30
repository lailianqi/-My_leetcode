#include <list>
#include <map>
#include <unordered_map>
using namespace std;
// 直接看的LeetCode的答案 这题 这个阶段暂时没办法不看答案搞定
// https://discuss.leetcode.com/topic/69436/concise-c-o-1-solution-using-3-hash-maps-with-explanation
// 第二个链接的答案是投票最高的答案 和上面一个链接的答案思想是一样的
// 不过是Java写的
// https://discuss.leetcode.com/topic/69737/java-o-1-very-easy-solution-using-3-hashmaps-and-linkedhashset
class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> m;          // key to {value,freq};
    unordered_map<int, list<int>::iterator> mIter; // key to list iterator;
    unordered_map<int, list<int>> fm;              // freq to key list;
  public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (m.count(key) == 0) {
            return -1;
        }
        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mIter[key] = --fm[m[key].second].end();
        if (fm[minFreq].size() == 0)
            minFreq++;
        return m[key].first;
    }

    void put(int key, int value) {
        if (cap <= 0)
            return;
        int storedValue = get(key);
        if (storedValue != -1) {
            m[key].first = value;
            return;
        }
        if (size >= cap) {
            m.erase(fm[minFreq].front());
            mIter.erase(fm[minFreq].front());
            fm[minFreq].pop_front();
            size--;
        }
        m[key] = {value, 1};
        fm[1].push_back(key);
        mIter[key] = --fm[1].end();
        minFreq = 1;
        size++;
    }
};