#include <vector>
#include <set>
using namespace std;
//这种解法的时间复杂度非常的高 跑了1709 ms
class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int m = (i + k <= nums.size() - 1) ? i + k : nums.size() - 1;
            for (int j = i + 1; j <= m; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
//自己的改进的写法，自己想出来的，跑了32ms。核心思想 slide window
// leetcode存在相同的解法,下面是链接
// https://discuss.leetcode.com/topic/15305/simple-java-solution?page=1
class Solution_0 {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        set<int> directory;
        for (int i = 0; i < nums.size(); i++) {
            if (directory.count(nums[i]) > 0) {
                return true;
            }
            directory.insert(nums[i]);
            if (directory.size() == k + 1) {
                directory.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// leetcode的解法，也是slide window
//这个写法不错
// https://discuss.leetcode.com/topic/20826/c-6-line-solution-simple-code-and-easy-understanding
class Solution_1 {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        set<int> cand;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                cand.erase(nums[i - k - 1]);
            if (!cand.insert(nums[i]).second)
                return true;
        }
        return false;
    }
};

void test() {
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 0};
    s.containsNearbyDuplicate(nums, 5);
}