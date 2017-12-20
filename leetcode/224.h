#include <string>
#include <stack>
using namespace std;
// 第一次没有写出来
//下面是leetcode的答案
// https://discuss.leetcode.com/topic/15816/iterative-java-solution-with-stack/7
class Solution {
  public:
    int calculate(string s) {
        stack<int> intStack;
        int result = 0, number = 0, sign = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                number = 10 * number + (int)(s[i] - '0');
            } else if (s[i] == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (s[i] == '(') {
                intStack.push(result);
                intStack.push(sign);
                sign = 1;
                result = 0;
            } else if (s[i] == ')') {
                result += sign * number;
                number = 0;
                result *= intStack.top();
                intStack.pop();
                result += intStack.top();
                intStack.pop();
            }
        }
        result += sign * number;
        return result;
    }
};

//另外一种写法
//把括号拆开
// https://discuss.leetcode.com/topic/15816/iterative-java-solution-with-stack/6
class Solution_0 {
  public:
    int calculate(string s) {
        stack<int> intStack;
        int result = 0, number = 0, sign = 1;
        intStack.push(sign);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                number = 10 * number + (int)(s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                result += sign * number;
                sign = intStack.top() * (s[i] == '+' ? 1 : -1);
                number = 0;
            } else if (s[i] == '(') {
                intStack.push(sign);
            } else if (s[i] == ')') {
                intStack.pop();
            }
        }
        result += sign * number;
        return result;
    }
};