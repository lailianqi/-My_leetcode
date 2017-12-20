#include <stack>
#include <string>
#include <vector>
// You are here!
// Your runtime beats 47.24 % of cpp submissions
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> RPNstack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int left = RPNstack.top();
                RPNstack.pop();
                int right = RPNstack.top();
                RPNstack.pop();
                if (tokens[i] == "+") {
                    RPNstack.push(left + right);
                } else if (tokens[i] == "-") {
                    RPNstack.push(right - left);
                } else if (tokens[i] == "*") {
                    RPNstack.push(left * right);
                } else {
                    if (left == 0) {
                        RPNstack.push(0);
                    } else
                        RPNstack.push(right / left);
                }
            } else {
                RPNstack.push(atoi(tokens[i].c_str()));
            }
        }
        return RPNstack.top();
    }
};

class Solution_0 {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> RPNstack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int left = RPNstack.top();
                RPNstack.pop();
                int right = RPNstack.top();
                RPNstack.pop();
                RPNstack.push(cal(right, tokens[i][0], left));
            } else {
                RPNstack.push(atoi(tokens[i].c_str()));
            }
        }
        return RPNstack.top();
    }
    int cal(int a, char p, int b) {
        switch (p) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                return 0;
            return a / b;
        }
        return -1;
    }
};

//另外一种简单且简洁的写法,这里就不列出了
// https://discuss.leetcode.com/topic/18179/accepted-clean-java-solution