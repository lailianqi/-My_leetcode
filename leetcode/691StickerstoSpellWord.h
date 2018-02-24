
#include <algorithm>
#include <cinttypes>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 这题刚开始没看懂 所以最后直接看的答案
// 来自LeetCode的答案
// https://leetcode.com/problems/stickers-to-spell-word/discuss/108318/C++JavaPython-DP-+-Memoization-with-optimization-29-ms-(C++)?page=1
class Solution {
  public:
    int minStickers(vector<string> &stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        unordered_map<string, int> dp;
        // count characters a-z for each sticker
        for (int i = 0; i < m; i++) {
            for (char c : stickers[i]) {
                mp[i][c - 'a']++;
            }
        }
        dp[""] = 0; //递归的出口
        return helper(dp, mp, target);
    }

  private:
    int helper(unordered_map<string, int> &dp, vector<vector<int>> &mp,
               string target) {
        if (dp.count(target)) {
            return dp[target];
        }
        int ans = INT_MAX, m = mp.size();
        vector<int> tar(26, 0);
        for (char c : target) {
            tar[c - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            if (mp[i][target[0] - 'a'] > 0) {
                string s;
                for (int j = 0; j < 26; j++) {
                    if (tar[j] - mp[i][j] > 0) {
                        s += string(tar[j] - mp[i][j], 'a' + j);
                    }
                }
                int temp = helper(dp, mp, s);
                ans = temp == -1 ? -1 : min(ans, 1 + temp);
            }
        }
        return dp[target] = ans == INT_MAX ? -1 : ans;
    }
};

typedef unsigned int uint;
// 还有一种很超前的写法
// https://leetcode.com/problems/stickers-to-spell-word/discuss/108333/Rewrite-of-contest-winner's-solution
// http://blog.csdn.net/thesnowboy_2/article/details/78180542
class Solution_0 {
  public:
    int minStickers(vector<string> &stickers, string target) {
        int n = target.size(), N = 1 << n;
        vector<uint> dp(N, -1);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] != -1) {
                for (string &str : stickers) {
                    int sup = i;
                    for (char c : str) {
                        for (int j = 0; j < n; j++) {
                            if (target[j] == c && ((sup >> j) & 1) == 0) {
                                sup |= 1 << j;
                                break;
                            }
                        }
                    }
                    dp[sup] = min(dp[sup], dp[i] + 1);
                }
            }
        }
        return dp[N - 1];
    }
};
// 这个是上面方法的解释原理的版本 来自LeetCode
// https://leetcode.com/problems/stickers-to-spell-word/discuss/108333/Rewrite-of-contest-winner's-solution
class Solution_1 {
  public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), m = 1 << n; // if target has n chars, there will be m=2^n-1 subset of characters in target
        vector<uint> dp(m, -1); // use index 0 - 2^n-1 as bitmaps to represent each subset of all chars of target
        dp[0] = 0; // first thing we know is : dp[empty set] requires 0 stickers,
        for (int i = 0; i < m; i++) { // for every subset i, start from 00000...(emptyset) to 111111...(the target)
            if (dp[i] == -1) continue;
            for (string& s : stickers) { // try use each sticker as an char provider to populate a super-set of i,
                int sup = i;
                for (char c : s) { // to do that, for each char in the sticker, 
                    for (int r = 0; r < n; r++) {
                        if (target[r] == c && !((sup >> r) & 1)) { // try apply it on a missing char in the subset of target
                            sup |= 1 << r;
                            break;
                        }
                    }
                }
               // after you apply all possible chars in a sticker, you get an superset that take 1 extra sticker than subset
               // would take, so you can try to update the superset's minsticker number with dp[sub]+1;
                dp[sup] = min(dp[sup], dp[i] + 1); 
            }
        }
        return dp[m - 1]; // and the ultimate result
    }
};