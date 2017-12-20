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
                        dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 > 0)
                                                     ? dp[i - dp[i - 1] - 2]
                                                     : 0);
                    }
                }
                result = max(result, dp[i]);
            }
        }
        return result;
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