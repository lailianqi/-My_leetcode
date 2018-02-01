#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 我的dp想歪了 下面是不对的答案 最初的想法
class Solution {
  public:
    int removeBoxes(vector<int> &boxes) {}
    void helper(vector<int> &boxes, unordered_map<string, int> memo) {
        int m = boxes.size();
        for (int i = 0; i < m; i++) {
            if (boxes[i] != boxes[i + 1] || i == m - 1) {
            }
        }
    }
    vector<int> deleString(vector<int> &boxes, int pos) {
        int i = pos - 1, j = pos + 1;
        vector<int> res;
        while (boxes[i] == boxes[pos])
            i--;
        while (boxes[j] == boxes[pos])
            j++;
        for (int k = 0; k <= i; k++) {
            res.push_back(boxes[i]);
        }
        for (int k = j; k < boxes.size(); k++) {
            res.push_back(boxes[i]);
        }
        return res;
    }
    string to_string(vector<int> &boxes) {
        string res;
        for (int i = 0; i < boxes.size(); i++) {
            res.push_back(boxes[i] + '0');
        }
        return res;
    }
};

// 来自LeetCode的答案 老实说 这个dp是我见过的最难分析的dp
// https://discuss.leetcode.com/topic/84687/java-top-down-and-bottom-up-dp-solutions
// https://www.cnblogs.com/grandyang/p/6850657.html
// Top-down DP:
class Solution_0 {
  public:
    int removeBoxes(vector<int> &boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0};
        return helper(boxes, 0, n - 1, 0, dp);
    }
    int helper(vector<int> &boxes, int i, int j, int k, int dp[100][100][100]) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }
        for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++)
            ;
        int res = (k + 1) * (k + 1) + helper(boxes, i + 1, j, 0, dp);
        for (int m = i + 1; m <= j; m++) {
            if (boxes[i] == boxes[m]) {
                res = max(res, helper(boxes, i + 1, m - 1, 0, dp) +
                                   helper(boxes, m, j, k + 1, dp));
            }
        }
        dp[i][j][k] = res;
        return res;
    }
};

// Bottom-up DP:
// 感觉还是有点疑问 对于这个解法 原因找到了（计算多余的k 对结构是没有影响的）
// https://discuss.leetcode.com/topic/84687/java-top-down-and-bottom-up-dp-solutions
class Solution_1 {
  public:
    int removeBoxes(vector<int> &boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0};
        for (int r = 1; r < n; r++) {
            for (int j = r; j < n; j++) {
                int i = j - r;
                //计算了多余的k dp自底向上 都是计算全部的值
                for (int k = 0; k <= i; k++) {
                    int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for (int m = i + 1; m <= j; m++) {
                        if (boxes[m] == boxes[i]) {
                            res =
                                max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                        }
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        return (n == 0 ? 0 : dp[0][n - 1][0]);
    }
};