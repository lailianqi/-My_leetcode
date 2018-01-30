#include <unordered_map>
#include <vector>
using namespace std;
// 草 写不出来啊
// LeetCode的答案
// https://discuss.leetcode.com/topic/67413/detailed-explanation-for-java-o-n-2-solution
// http://blog.csdn.net/u013007900/article/details/53321398
// https://discuss.leetcode.com/topic/66840/c-_dp_accepted
// https://discuss.leetcode.com/topic/67012/java-15-lines-solution
// https://discuss.leetcode.com/topic/67012/java-15-lines-solution/7
class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int res = 0;
        vector<unordered_map<int, int>> dp(A.size());
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - A[j];
                if (diff < INT_MIN || diff > INT_MAX)
                    continue;
                int d = (int)diff;
                dp[i][d]++;
                if (dp[j].find(d) != dp[j].end()) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};