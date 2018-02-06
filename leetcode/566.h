#include <algorithm>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                res[counter / c][counter % c] = nums[i][j];
                counter++;
            }
        }
        return res;
    }
};
// 上面的稍微的改进版 答案来自LeetCode 其实思想和上面自己的答案一模一样
// https://discuss.leetcode.com/topic/87851/java-concise-o-nm-time
// https://discuss.leetcode.com/topic/87901/one-loop
class Solution_0 {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = nums[i / n][i % n];
        }
        return res;
    }
};

// python的写法
// https://discuss.leetcode.com/topic/87899/python-solutions

void test() {
    Solution s;
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    s.matrixReshape(nums, 1, 4);
}