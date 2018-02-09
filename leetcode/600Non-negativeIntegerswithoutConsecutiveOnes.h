#include <string>
#include <vector>
using namespace std;
// 这题我现在写不出来 直接看的LeetCode的答案
// https://discuss.leetcode.com/topic/90571/java-solution-dp
// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
// http://www.bubuko.com/infodetail-2093055.html
// https://www.jianshu.com/p/e30cd697b36b
class Solution {
  public:
    int findIntegers(int num) {
        if (num <= 0)
            return 0;
        string s = toBinaryString(num);
        int len = s.size(), res = 0;
        vector<int> a(len, 0), b(len, 0);
        a[0] = b[0] = 1;
        for (int i = 1; i < a.size(); i++) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }
        res = a[len - 1] + b[len - 1];
        reverse(s.begin(), s.end());
        for (int i = len - 2; i >= 0; i--) {
            if (s[i] == '1' && s[i + 1] == '1')
                break;
            else if (s[i] == '0' && s[i + 1] == '0')
                res -= b[i];
        }
        return res;
    }
    string toBinaryString(int num) {
        string ret;
        int mask = 1;
        while (num >= mask) {
            if ((num & mask) >= 1)
                ret = '1' + ret;
            else
                ret = '0' + ret;
            mask <<= 1;
        }
        return ret;
    }
};

// 解释最清楚的答案 我觉的这个答案最牛逼
// https://discuss.leetcode.com/topic/90639/c-non-dp-o-32-fibonacci-solution
// 原来和官方题解一样 官方题解有演示的过程
// https://leetcode.com/articles/non-negative-integers-without-consecutive-ones/
class Solution_0 {
  public:
    int findIntegers(int num) {
        vector<int> dp(32, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num & (1 << k)) {
                ans += dp[k];
                if (pre_bit)
                    return ans;
                pre_bit = 1;
            } else {
                pre_bit = 0;
            }
            k--;
        }
        return ans + 1;
    }
};