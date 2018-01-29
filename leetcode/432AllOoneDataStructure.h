#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 直接看的LeetCode的答案 以我的水平 暂时写不出来
// https://discuss.leetcode.com/topic/63683/all-in-o-1-with-detailed-explantation
class AllOne {
  public:
    struct Row {
        list<string> strs;
        int val;
        Row(const string &s, int x) : strs({s}), val(x) {}
    };
    unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>>
        strmap;
    list<Row> matrix;
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key by
     * 1. */
    void inc(string key) {
        if (strmap.find(key) == strmap.end()) {
            if (matrix.empty() || matrix.back().val != 1) {
                auto newrow = matrix.emplace(matrix.end(), key, 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else {
                auto newrow = --matrix.end();
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
        } else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            auto lastrow = row;
            --lastrow;
            if (lastrow == matrix.end() || lastrow->val != row->val + 1) {
                auto newrow = matrix.emplace(row, key, row->val + 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else {
                auto newrow = lastrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty())
                matrix.erase(row);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the
     * data structure. */
    void dec(string key) {
        if (strmap.find(key) == strmap.end()) {
            return;
        } else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            if (row->val == 1) {
                row->strs.erase(col);
                if (row->strs.empty())
                    matrix.erase(row);
                strmap.erase(key);
                return;
            }
            auto nextrow = row;
            ++nextrow;
            if (nextrow == matrix.end() || nextrow->val != row->val - 1) {
                auto newrow = matrix.emplace(nextrow, key, row->val - 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else {
                auto newrow = nextrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty())
                matrix.erase(row);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty() ? "" : matrix.front().strs.front();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty() ? "" : matrix.back().strs.front();
    }
};

// sp大神的写法 更加的短 更加的容易理解
// https://discuss.leetcode.com/topic/63827/c-solution-with-comments
namespace ss {
class AllOne {
  private:
    struct Bucket {
        int value;
        unordered_set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;

  public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key by
     * 1. */
    void inc(string key) {
        if (!bucketOfKey.count(key)) {
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
        }
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1) {
            next = buckets.insert(next, {bucket->value + 1, {}});
        }
        next->keys.insert(key);
        bucketOfKey[key] = next;

        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the
     * data structure. */
    void dec(string key) {
        if (!bucketOfKey.count(key)) {
            return;
        }
        auto prev = bucketOfKey[key], bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1) {
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            }
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
};
} // namespace ss