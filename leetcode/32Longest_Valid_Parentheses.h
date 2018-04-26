#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    //标准答案改写版
    int longestValidParentheses(string s) {
        stack<int> sta;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                sta.push(i);
            } else {
                if (!sta.empty() && s[sta.top()] == '(') {
                    sta.pop();
                } else
                    sta.push(i);
            }
        }
        int right = s.length(), left = 0;
        if (sta.empty()) {
            result = right;
            return result;
        }
        while (!sta.empty()) {
            left = sta.top();
            sta.pop();
            result = max(result, right - left - 1);
            right = left;
        }
        result = max(result, right);
        return result;
    }
    // DP解法
    int longestValidParentheses1(string s) {
        int result = 0;
        int *dp = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i] = 0;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2) > 0 ? dp[i - 2] + 2 : 2;
                    result = max(result, dp[i]);
                } else {
                    if ((i - dp[i - 1] - 1) >= 0 &&
                        s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 +
                                ((i - dp[i - 1] - 2 > 0) ? dp[i - dp[i - 1] - 2]
                                                         : 0);
                    }
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};

// 第二遍刷的时候添加的 改进版 参照的LeetCode 比上面的解法牛逼多了
// https://leetcode.com/problems/longest-valid-parentheses/discuss/14126/My-O(n)-solution-using-a-stack
class Solution_0 {
  public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        s = ")" + s;
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')' && s[stk.top()] == '(') {
                stk.pop();
                res = max(res, i - stk.top());
            } else {
                stk.push(i);
            }
        }
        return res;
    }
};

// 第二遍的时候上面的变种
// https://leetcode.com/problems/longest-valid-parentheses/discuss/14167/Simple-JAVA-solution-O(n)-time-one-stack
class Solution_1 {
  public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && stk.top() != -1 && s[stk.top()] == '(') {
                stk.pop();
                res = max(res, i - stk.top());
            } else {
                stk.push(i);
            }
        }
        return res;
    }
};

// dp的解法请参照python的LeetCode版本
// dp参考的官方题解的网址
// https://leetcode.com/problems/longest-valid-parentheses/discuss/14133/My-DP-O(n)-solution-without-using-stack

class Solution_2 {
  public:
    int longestValidParentheses(string s) {
        s = ")" + s;
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

void test() {
    Solution s;
    cout << s.longestValidParentheses1(
                ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(()"
                ")()()(((()))))()((()))(((())()((()()())((())))(())))())((()())"
                "()()((()((())))))((()(((((()((()))(()()(())))((()))()))())")
         << endl;
}