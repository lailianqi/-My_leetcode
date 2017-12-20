#include <vector>
using namespace std;
// 自己的解法 用的dp  成功的ac了 但是时间效率非常的差 发现刚开始的这种思路并不对
class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int m = A.size(), res = 0;
        vector<vector<bool>> dp(m, vector<bool>(m, false));
        for (int i = 0; i < m - 1; i++) {
            dp[i][i + 1] = true;
        }
        for (int r = 3; r <= m; r++) {
            for (int i = 0; i <= m - r; i++) {
                int j = i + r - 1;
                if (dp[i][j - 1] && (A[j - 2] + A[j] == 2 * A[j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
// leetcode的解法 写的非常的好 本质上就是dp
// https://discuss.leetcode.com/topic/63302/simple-java-solution-9-lines-2ms
class Solution_0 {
  public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int m = A.size(), res = 0, curr = 0;
        for (int i = 2; i < m; i++) {
            if (2 * A[i - 1] == (A[i] + A[i - 2])) {
                curr++;
                res += curr;
            } else {
                curr = 0;
            }
        }
        return res;
    }
};
// leetcode的解法 最原始的dp的解法
// https://discuss.leetcode.com/topic/62992/3ms-c-standard-dp-solution-with-very-detailed-explanation
class Solution_1 {
  public:
    int numberOfArithmeticSlices(vector<int> &A) {
        vector<int> dp(A.size(), 0);
        int total = 0;
        for (int i = 2; i < A.size(); i++) {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
                dp[i] = dp[i - 1] + 1;
            }
            total += dp[i];
        }
        return total;
    }
};
void test() {
    Solution_0 s;
    vector<int> A = {1, 2, 3, 4};
    s.numberOfArithmeticSlices(A);
}