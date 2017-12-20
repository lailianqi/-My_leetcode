#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;
//第一种方法 速度不够快
class RandomizedSet {
  public:
    /** Initialize your data structure here. */
    RandomizedSet() { srand((unsigned)time(nullptr)); }

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        bool result = (numsSet.find(val) == numsSet.end());
        if (!result)
            return false;
        numsSet.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        bool result = (numsSet.find(val) != numsSet.end());
        if (!result)
            return false;
        numsSet.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int sz = numsSet.size();
        auto it = numsSet.begin();
        std::advance(it, rand() % sz);
        return *it;
    }

  private:
    unordered_set<int> numsSet;
};

// leetcode答案
// https://discuss.leetcode.com/topic/53216/java-solution-using-a-hashmap-and-an-arraylist-along-with-a-follow-up-131-ms
//速度大幅度提升
class Solution {
    class RandomizedSet {
      public:
        /** Initialize your data structure here. */
        RandomizedSet() { srand((unsigned)time(nullptr)); }

        /** Inserts a value to the set. Returns true if the set did not already
         * contain the specified element. */
        bool insert(int val) {
            if (indexMap.find(val) != indexMap.end())
                return false;
            nums.push_back(val);
            indexMap[val] = nums.size() - 1;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the
         * specified element. */
        //下面的函数不需要考虑是否是最后一位的情况也就是back的位置
        bool remove(int val) {
            if (indexMap.find(val) == indexMap.end())
                return false;
            nums[indexMap[val]] = nums.back();
            indexMap[nums.back()] = indexMap[val];
            nums.pop_back();
            indexMap.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() { return nums[rand() % nums.size()]; }

      private:
        vector<int> nums;
        unordered_map<int, int> indexMap;
    };
};