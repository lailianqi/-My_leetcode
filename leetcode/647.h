#include <string>
#include <vector>
using namespace std;
// 自己的第一种方案  成功ac
// leetcode上面差不多写法的答案
// https://leetcode.com/problems/palindromic-substrings/discuss/105707/Java-DP-solution-based-on-longest-palindromic-substring
class Solution {
  public:
    int countSubstrings(string s) {
        int m = s.size(), res = 0;
        vector<vector<bool>> dp(m, vector<bool>(m, false));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i; j < m; j++) {
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};

// leetcode的答案 第二种写法 从中间左右延伸的解法
// https://leetcode.com/problems/palindromic-substrings/discuss/105689/Java-solution-8-lines-extendPalindrome?page=1
// https://leetcode.com/problems/palindromic-substrings/discuss/105688/Very-Simple-Java-Solution-with-Detail-Explanation

// sp大神一行的解法
// https://leetcode.com/problems/palindromic-substrings/discuss/105694/Oneliner-Python