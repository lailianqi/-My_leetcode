#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
// 下面是自己的第一种解法 运行效率一般
// 下面是leetcode上java的解法的链接 思路是一样的
// https://discuss.leetcode.com/topic/76249/java-20-lines-backtracking-solution-using-set-beats-100
class Solution {
  public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        set<vector<int>> result; //只能用set 不能用unordered_set 否则报错
        vector<int> list;
        helper(nums, result, 0, list);
        return vector<vector<int>>(result.begin(), result.end());
    }
    void helper(vector<int> &nums, set<vector<int>> &result, int left,
                vector<int> &list) {
        if (list.size() >= 2) {
            result.insert(list);
        }
        for (int i = left; i < nums.size(); i++) {
            if (list.empty() || list.back() <= nums[i]) {
                list.push_back(nums[i]);
                //当初把i + 1 写成left + 1，调错调了很久
                helper(nums, result, i + 1, list);
                list.pop_back();
            }
        }
    }
};

//来自与leetcode的不同于上面的解法
// https://discuss.leetcode.com/topic/76273/java-solution-beats-100
// https://discuss.leetcode.com/topic/76211/clean-20ms-solution
// https://discuss.leetcode.com/topic/76274/c-dfs-solution-using-unordered_set

class Solution_0 {
  public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> list;
        helper(nums, result, 0, list);
        return result;
    }
    void helper(vector<int> &nums, vector<vector<int>> &result, int left,
                vector<int> &list) {
        if (list.size() >= 2) {
            result.push_back(list);
        }
        unordered_set<int> dir;
        for (int i = left; i < nums.size(); i++) {
            if (dir.count(nums[i]) == 0 &&
                (list.empty() || list.back() <= nums[i])) {
                list.push_back(nums[i]);
                helper(nums, result, i + 1, list);
                list.pop_back();
                dir.insert(nums[i]);
            }
        }
    }
};