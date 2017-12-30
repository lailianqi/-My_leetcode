#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
//第一种写法 成功ac 但是运行的效率太低
class Solution {
  public:
    bool makesquare(vector<int> &nums) {
        int sideLineSum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < 4 || sideLineSum % 4 != 0 ||
            *max_element(nums.begin(), nums.end()) > sideLineSum / 4) {
            return false;
        }
        vector<int> sums(4, 0);
        return helper(nums, 0, sums, sideLineSum / 4);
    }
    bool helper(vector<int> &nums, int index, vector<int> &sums, int target) {
        if (index == nums.size()) {
            if (sums[0] == target && sums[1] == target && sums[2] == target) {
                return true;
            }
            return false;
        }
        for (int i = 0; i < 4; i++) {
            if (sums[i] + nums[index] <= target) {
                sums[i] += nums[index];
                if (helper(nums, index + 1, sums, target)) {
                    return true;
                }
                sums[i] -= nums[index];
            }
        }
        return false;
    }
};
// LeetCode的答案  改进的写法
// https://discuss.leetcode.com/topic/72107/java-dfs-solution-with-explanation/2
// https://discuss.leetcode.com/topic/72107/java-dfs-solution-with-explanation/44?page=3
// https://discuss.leetcode.com/topic/74077/cpp-6ms-solution-with-dfs
class Solution_0 {
  public:
    bool makesquare(vector<int> &nums) {
        int sideLineSum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < 4 || sideLineSum % 4 != 0 ||
            *max_element(nums.begin(), nums.end()) > sideLineSum / 4) {
            return false;
        }
        vector<int> sums(4, 0);
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
        return helper(nums, 0, sums, sideLineSum / 4);
    }
    bool helper(vector<int> &nums, int index, vector<int> &sums, int target) {
        if (index == nums.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            if (sums[i] + nums[index] <= target) {
                sums[i] += nums[index];
                if (helper(nums, index + 1, sums, target)) {
                    return true;
                }
                sums[i] -= nums[index];
            }
        }
        return false;
    }
};

// leetcode 上新颖的解法 用的bit
// https://discuss.leetcode.com/topic/72232/c-bit-masking-dp-solution-with-detailed-comments
