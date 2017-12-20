#include <vector>
using namespace std;
//这题发现规律就很容易写出来
//下面的链接是网上写的比较好的题解的链接
// https://www.cnblogs.com/grandyang/p/5869791.html
// leetcode的解释更加的牛逼
// https://discuss.leetcode.com/topic/58459/java-o-n-solution-with-explanation
// https://discuss.leetcode.com/topic/58616/java-solution-o-n-with-non-mathametical-explaination/7
class Solution {
  public:
    int maxRotateFunction(vector<int> &A) {
        if (A.empty()) {
            return 0;
        }
        int sum = 0, m = A.size(), res = 0;
        vector<int> dp(m, 0);
        for (int i = 0; i < m; i++) {
            dp[0] = dp[0] + i * A[i];
            sum += A[i];
        }
        res = dp[0];
        for (int i = 1; i < m; i++) {
            dp[i] = dp[i - 1] + sum - m * A[m - i];
            res = max(res, dp[i]);
        }
        return res;
    }
};
//上面答案的改进版
// https://discuss.leetcode.com/topic/58616/java-solution-o-n-with-non-mathametical-explaination/8
class Solution_0 {
  public:
    int maxRotateFunction(vector<int> &A) {
        int sum = 0, m = A.size(), iteration = 0;
        for (int i = 0; i < m; i++) {
            iteration = iteration + i * A[i];
            sum += A[i];
        }
        int res = iteration;
        for (int i = 1; i < m; i++) {
            iteration = iteration + sum - m * A[m - i];
            res = max(res, iteration);
        }
        return res;
    }
};