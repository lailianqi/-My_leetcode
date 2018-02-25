#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 73周周赛 未参加
// 这道题没看懂 所以没写出来 直接看的LeetCode的答案
// 来自LeetCode的答案
// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116544/O(N)-time-and-O(1)-space-C++JavaPython
// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116536/Easy-and-very-concise-clear-In-java

// 详细的解释在这里 涉及公式的推导
// https://cs.stackexchange.com/questions/66658/domino-and-tromino-combined-tiling

// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1+dpn-3
// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116544/O(N)-time-and-O(1)-space-C++JavaPython
class Solution {
  public:
    int numTilings(int N) {
        int mod = 1000000007;
        vector<int> dp(N + 1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for (int i = 4; i <= N; i++) {
            dp[i] = dp[i - 1] * 2 % mod + dp[i - 3];
            dp[i] %= mod;
        }
        return dp[N];
    }
};