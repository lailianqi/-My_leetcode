#include <string>
#include <iostream>
#include <stack>
using namespace std;
//没写出来
//错误的答案 通不过ac 自己的第一种思路
class Solution {
  public:
    string decodeString(string s) {
        string result;
        int num = 0, i = 0;
        while (i < s.size()) {
            num = 0;
            while (isdigit(s[i]) && i < s.size()) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            if (i < s.size() && s[i] == '[') {
                i++;
                int start = i;
                while (i < s.size() && s[i] != ']') {
                    i++;
                }
                string temp = s.substr(start, i - start);
                for (int k = 0; k < num; k++) {
                    result = result + temp;
                }
                i++;
            }
            if (i < s.size() && isalpha(s[i])) {
                int start = i;
                while (i < s.size() && isalpha(s[i])) {
                    i++;
                }
                result += s.substr(start, i - start);
            }
        }
        return result;
    }
};
// leetcode的答案 非常的简单易懂
// https://discuss.leetcode.com/topic/57228/0ms-simple-c-solution/20
class Solution_0 {
  public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    string decodeString(string &s, int &i) {
        string res;
        for (int num = 0; i < s.size() && s[i] != ']'; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (isalpha(s[i])) {
                res.push_back(s[i]);
            } else if (s[i] == '[') {
                string bracket = decodeString(s, ++i);
                //这里用的while 居然内存相对于答案里for的用法会内存超出
                //自己的电脑上没事
                while (num--) {
                    res += bracket;
                }
            }
        }
        return res;
    }
};
// leetcode的答案 比上面的解法可能更好一点
// https://discuss.leetcode.com/topic/57228/0ms-simple-c-solution
class Solution_1 {
  public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    string decodeString(string &s, int &i) {
        string res;
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            } else {
                //[出现前一定有数字
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i++] - '0';
                }
                string temp = decodeString(s, ++i); //'['
                i++;                                //']'
                while (num--) {
                    res += temp;
                }
            }
        }
        return res;
    }
};
//使用stack的解法 leetcode的答案
// https://discuss.leetcode.com/topic/57159/simple-java-solution-using-stack/4
class Solution_2 {
  public:
    string decodeString(string s) {
        string res;
        stack<int> intStack;
        stack<string> strStack;
        for (int i = 0, num = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                intStack.push(num);
                strStack.push(res);
                res = "";
                num = 0;
            } else if (s[i] == ']') {
                string temp = res;
                res = strStack.top();
                for (int k = intStack.top(); k > 0; k--) {
                    res += temp;
                }
                intStack.pop();
                strStack.pop();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
void test() {
    Solution s;
    cout << s.decodeString("3[a]2[bc]");
}