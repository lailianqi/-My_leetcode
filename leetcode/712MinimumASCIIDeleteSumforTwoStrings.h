#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using namespace std;

//自己的第一种解法 成功ac 这个题目我觉得非常的不错
//其实我的第一种方案写复杂了  我的第二种方案更好
class Solution {
    struct Comparator {
        bool operator()(const std::pair<int, int> &lhs,
                        const std::pair<int, int> &rhs) const {
            return lhs.second < rhs.second;
        }
    };
    // auto comp = [](pair<int, int> &a, pair<int, int> &b) {
    //     return a.first != b.first ? a.first < b.first : a.second <
    //     b.second;
    // };
  public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<pair<int, int>>> dp(
            m + 1, vector<pair<int, int>>(n + 1, {0, 0}));
        dp[0][0] = {1, 0};
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = {dp[i - 1][j - 1].first + 1,
                                dp[i - 1][j - 1].second +
                                    (s1[i - 1] - 'a' + 97)};
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], Comparator());
                }
            }
        }
        // int result = 0;
        // for (int i = 0; i < m; i++) {
        //     result += s1[i] - 'a' + 97;
        // }
        // for (int i = 0; i < n; i++) {
        //     result += s2[i] - 'a' + 97;
        // }
        // return result - 2 * dp[m][n].second;
        return accumulate(
                   s1.begin(), s1.end(), 0,
                   [](int sum, char &a) { return sum + (a - 'a' + 97); }) +
               accumulate(
                   s2.begin(), s2.end(), 0,
                   [](int sum, char &a) { return sum + (a - 'a' + 97); }) -
               2 * dp[m][n].second;
    }
};

// 自己的第二种方案 成功ac
class Solution_0 {
  public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + (s1[i - 1]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return accumulate(s1.begin(), s1.end(), 0,
                          [](int sum, char &a) { return sum + a; }) +
               accumulate(s2.begin(), s2.end(), 0,
                          [](int sum, char &a) { return sum + a; }) -
               2 * dp[m][n];
    }
};

// LeetCode的答案
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/discuss/108828/C++-DP-with-explanation
class Solution_1 {
  public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// 上面的改进版 来自LeetCode
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/discuss/108828/C++-DP-with-explanation
class Solution_2 {
  public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> dp(n + 1, 0);
        for (int j = 1; j <= n; j++)
            dp[j] = dp[j - 1] + s2[j - 1];
        for (int i = 1; i <= m; i++) {
            int t1 = dp[0];
            dp[0] += s1[i - 1];
            for (int j = 1; j <= n; j++) {
                int t2 = dp[j];
                dp[j] = s1[i - 1] == s2[j - 1]
                            ? t1
                            : min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                t1 = t2;
            }
        }
        return dp[n];
    }
};