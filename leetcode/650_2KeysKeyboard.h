#include <vector>
using namespace std;

/*
The algorithm iterates through the factors backwards, selecting the greatest one
first. This ensures that the amount of copy/paste operations is minimal. For
instance, consider the number 8. You can do it in three ways: Copy (1A), paste
(2A), paste (3A), paste (4A), paste (5A), paste (6A), paste (7A), paste (8A)
Copy (1A), paste (2A), copy (2A), paste (4A), paste (6A), paste (8A)
Copy (1A), paste (2A), paste (2A), copy (4A), paste (8A)
Because 4 is 8's highest factor, it will give the optimal solution.
*/
//这题没有想到方法 直接看的答案
// 来自LeetCode的答案
// https://leetcode.com/problems/2-keys-keyboard/description/
class Solution {
  public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = i / 2; j > 1; j--) {
                if (i % j == 0) {
                    dp[i] = dp[j] + (i / j);
                    break;
                }
            }
        }
        return dp[n];
    }
};

// 第二种解法 来自LeetCode
// https://leetcode.com/problems/2-keys-keyboard/discuss/105897/Loop-best-case-log(n)-no-DP-no-extra-space-no-recursion-with-explanation
class Solution_0 {
  public:
    int minSteps(int n) {
        int s = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                s += d;
                n /= d;
            }
        }
        return s;
    }
};