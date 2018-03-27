#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 这题现在是无法写出来的水平  直接看的答案
// https://www.cnblogs.com/grandyang/p/8045255.html   这个链接讲的挺好的
// https://blog.csdn.net/u014688145/article/details/78665218
// https://leetcode.com/problems/parse-lisp-expression/discuss/109721/C++-recursion-solution-with-explaination
class Solution {
  public:
    int evaluate(string expression) {
        unordered_map<string, int> myMap;
        return help(expression, myMap);
    }
    int help(string expression, unordered_map<string, int> myMap) {
        if ((expression[0] == '-') ||
            (expression[0] >= '0' && expression[0] <= '9')) {
            return stoi(expression);
        } else if (expression[0] != '(') {
            return myMap[expression];
        }
        string s = expression.substr(1, expression.size() - 2);
        int start = 0;
        string word = parse(s, start);
        if (word == "let") {
            while (true) {
                string variable = parse(s, start);
                if (start > s.size()) {
                    return help(variable, myMap);
                }
                string temp = parse(s, start);
                myMap[variable] = help(temp, myMap);
            }
        } else if (word == "add") {
            return help(parse(s, start), myMap) + help(parse(s, start), myMap);
        } else if (word == "mult") {
            return help(parse(s, start), myMap) * help(parse(s, start), myMap);
        }
    }

    // function to seperate each expression
    string parse(string &s, int &start) {
        int end = start + 1, temp = start, count = 1;
        if (s[start] == '(') {
            while (count != 0) {
                if (s[end] == '(') {
                    count++;
                } else if (s[end] == ')') {
                    count--;
                }
                end++;
            }
        } else {
            while (end < s.size() && s[end] != ' ') {
                end++;
            }
        }
        start = end + 1;
        return s.substr(temp, end - temp);
    }
};

// python的写法 应该更加的简单
// https://leetcode.com/problems/parse-lisp-expression/discuss/109709/python-solution-using-stacks.