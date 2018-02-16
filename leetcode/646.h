#include <algorithm>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
// leetcode上面的解法和这个解法思想差不多 写法稍有区别
// https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/105602/easy-dp
class Solution {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int m = pairs.size();
        vector<int> dp(m, 1);
        sort(pairs.begin(), pairs.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//上面的的另外的一种写法 来自LeetCode 就是上面自己的解法上面的链接中的写法
// https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/105602/easy-dp
class Solution_0 {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int m = pairs.size();
        vector<int> dp(m, 1);
        sort(pairs.begin(), pairs.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                dp[i] =
                    max(dp[i], pairs[i][0] > pairs[j][1] ? dp[j] + 1 : dp[j]);
            }
        }
        return dp.back();
    }
};

// 第三种方法 第一种方法的改进版 其实不需要dp就可以做 答案参考自LeetCode
// 这是这道题最优的解法
// https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/105607/4-Liner-Python-Greedy
class Solution_1 {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int m = pairs.size(), res = 0, curr = INT_MIN;
        sort(pairs.begin(), pairs.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        for (int i = 0; i < m; i++) {
            if (pairs[i][0] > curr) {
                res++;
                curr = pairs[i][1];
            }
        }
        return res;
    }
};