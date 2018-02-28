#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac
class Solution {
  public:
    bool isOneBitCharacter(vector<int> &bits) {
        int m = bits.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int i = 1; i <= m; i++) {
            dp[i] = (i >= 2 && (dp[i - 2] && bits[i - 2] == 1 &&
                                (bits[i - 1] == 0 || bits[i - 1] == 1))) ||
                    (dp[i - 1] && bits[i - 1] == 0);
        }
        return dp[m - 1] && bits[m - 1] == 0;
    }
};

// 来自LeetCode的答案
// https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/108969/Java-solution-1-or-2?page=2
class Solution_0 {
  public:
    bool isOneBitCharacter(vector<int> &bits) {
        int i = 0, m = bits.size();
        for (; i < m - 1;) {
            if (bits[i] == 0) {
                i++;
            } else {
                i += 2;
            }
        }
        return i == m - 1;
    }
};

// LeetCode的第二种方案
// https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/108967/JAVA-check-only-the-end-of-array
class Solution_1 {
  public:
    bool isOneBitCharacter(vector<int> &bits) {
        int i = 0, m = bits.size();
        int ones = 0;
        // Starting from one but last, as last one is always 0.
        for (int i = m - 2; i >= 0 && bits[i]; i--) {
            ones++;
        }
        return !(ones & 1);
    }
};