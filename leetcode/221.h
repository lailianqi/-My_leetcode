#include <vector>
#include <algorithm>
using namespace std;
// leetcode的答案，这题dp比较简单，但是没有想到，所以没有做出来
//下面是参考答案后改进的
// https://segmentfault.com/a/1190000003709497
// https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
class Solution {
  public:
    int maximalSquare(vector<string> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) +
                        (matrix[i - 1][j - 1] - '0');
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};
//再一次的改进版 自己写的 和答案一样
// https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space/2
class Solution_0 {
  public:
    int maximalSquare(vector<string> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int pre = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j], dp[j - 1]), pre) +
                            (matrix[i - 1][j - 1] - '0');
                    res = max(res, dp[j]);
                } else {
                    dp[j] = 0;
                }
                pre = temp;
            }
        }
        return res * res;
    }
};

//这是上面的改进版的写法
//改进了空间
void test() {
    vector<string> matrix = {"10100", "10111", "11111", "10010"};
    Solution s;
    s.maximalSquare(matrix);
}