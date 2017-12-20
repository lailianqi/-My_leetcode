#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;
//自己怎么改都通不过 这题某些部分有点难
// leetcode的答案
// https://discuss.leetcode.com/topic/54381/c-128m-solution-real-o-1-solution/6
class RandomizedCollection {
  public:
    /** Initialize your data structure here. */
    RandomizedCollection() { srand(time(0)); }

    /** Inserts a value to the collection. Returns true if the collection did
     * not already contain the specified element. */
    bool insert(int val) {
        bool has_key = pos_map.find(val) != pos_map.end();
        pos_map[val].insert(nums.size());
        nums.push_back(val);
        return !has_key;
    }

    /** Removes a value from the collection. Returns true if the collection
     * contained the specified element. */
    bool remove(int val) {
        if (pos_map.find(val) == pos_map.end())
            return false;

        int pos_rm = *(pos_map[val].begin());
        pos_map[val].erase(pos_rm);
        if (pos_map[val].empty())
            pos_map.erase(val);

        if (pos_rm != nums.size() - 1) {
            int pos_mv = nums.size() - 1, val_mv = nums.back();
            nums[pos_rm] = val_mv;
            pos_map[val_mv].erase(pos_mv);
            pos_map[val_mv].insert(pos_rm);
        }
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() { return nums[rand() % nums.size()]; }

  private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> pos_map;
};