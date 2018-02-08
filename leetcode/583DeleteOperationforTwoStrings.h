#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 这题居然不会写 直接看的答案 真是得抽自己耳光了
// 看到答案的标题知道是最长递增子序列问题 没点进去看代码
// 然后，自己写出了下面的代码
// https://discuss.leetcode.com/topic/89285/java-dp-solution-longest-common-subsequence
// https://discuss.leetcode.com/topic/89285/java-dp-solution-longest-common-subsequence/3
// https://discuss.leetcode.com/topic/89670/python-dp-solution
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = word1[i - 1] == word2[j - 1]
                               ? dp[i - 1][j - 1] + 1
                               : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[m][n] + m - dp[m][n];
    }
};

// 另外的一种思路 也非常的牛逼
// https://discuss.leetcode.com/topic/89283/java-dp-solution-same-as-edit-distance
// https://discuss.leetcode.com/topic/89283/java-dp-solution-same-as-edit-distance/8