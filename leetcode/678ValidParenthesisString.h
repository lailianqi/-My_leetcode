#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 超时的解法
class Solution {
  public:
    bool checkValidString(string s) { return helper(s, 0, 0); }
    bool helper(string &s, int start, int counter) {
        if (counter < 0) {
            return false;
        }
        for (int i = start; i < s.size(); i++) {
            if (s[i] == '(') {
                counter++;
            } else if (s[i] == ')') {
                counter--;
                if (counter < 0) {
                    return false;
                }
            } else if (s[i] == '*') {
                return helper(s, start + 1, counter - 1) ||
                       helper(s, start + 1, counter) ||
                       helper(s, start + 1, counter + 1);
            }
        }
        return counter == 0;
    }
};

// 来自LeetCode官方题解和讨论 最好的解法
// https://leetcode.com/problems/valid-parenthesis-string/solution/
class Solution_0 {
  public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            left += s[i] == '(' ? 1 : -1;
            right += s[i] != ')' ? 1 : -1;
            if (right < 0) {
                return false;
            }
            left = max(left, 0);
        }
        return left == 0;
    }
};

// LeetCode的答案 写的没上面好
// https://leetcode.com/problems/valid-parenthesis-string/discuss/107611/Very-concise-C++-solution-with-explaination.-No-DP
class Solution_1 {
  public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                lower++, upper++;
            } else if (s[i] == ')') {
                lower--, upper--;
            } else {
                lower--, upper++;
            }
            if (upper < 0) {
                return false;
            }
            lower = max(lower, 0);
        }
        return lower == 0;
    }
};