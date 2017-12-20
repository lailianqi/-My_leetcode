#include <vector>
#include <unordered_set>
using namespace std;

// O(n)的方法 没有想出来
// leetcode的解法
// https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap?page=1
class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        int maxValue = 0, mask = 0;
        unordered_set<int> dir;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            dir.clear();
            for (int element : nums) {
                dir.insert(mask & element);
            }
            int candidate = maxValue | (1 << i);
            for (int elememt : dir) {
                if (dir.count(elememt ^ candidate)) {
                    maxValue = candidate;
                    break;
                }
            }
        }
        return maxValue;
    }
};

// sp大神的解法
// https://discuss.leetcode.com/topic/63299/python-6-lines-bit-by-bitF