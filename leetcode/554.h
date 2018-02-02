#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// 自己的第一种方案 一次性ac 真是牛逼啊
// 卧槽 和LeetCode的答案基本上一模一样 更加牛逼了 下面是LeetCode的链接
// https://discuss.leetcode.com/topic/86151/i-don-t-think-there-is-a-better-person-than-me-to-answer-this-question
class Solution {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> dir;
        int res = 0, m = wall.size();
        for (int i = 0; i < wall.size(); i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                dir[sum]++;
                res = max(res, dir[sum]);
            }
        }
        return m - res;
    }
};

//自己对上面的改造版 改短了
class Solution_0 {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> dir;
        int res = 0, m = wall.size();
        for (int i = 0; i < wall.size(); i++) {
            for (int j = 0, sum = 0; j < wall[i].size() - 1; j++) {
                res = max(res, ++dir[sum += wall[i][j]]);
            }
        }
        return m - res;
    }
};