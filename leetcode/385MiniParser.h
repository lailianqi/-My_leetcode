#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to
    // it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
//没有努力写出来 发现自己对字符串处理方面还稍显不足
// leetcode的答案
// https://discuss.leetcode.com/topic/54277/short-java-recursive-solution
class Solution {
  public:
    NestedInteger deserialize(string s) { return helper(s); }
    NestedInteger helper(string s) {
        NestedInteger res;
        if (s.empty()) {
            return res;
        }
        if (s[0] != '[') {
            res.setInteger(stoi(s));
        } else if (s.size() > 2) {
            int bracketNum = 0, start = 1;
            for (int i = 1; i < s.size(); i++) {
                if (bracketNum == 0 && (s[i] == ',' || i == s.size() - 1)) {
                    res.add(helper(s.substr(start, i - start)));
                    start = i + 1;
                } else if (s[i] == '[')
                    bracketNum++;
                else if (s[i] == ']')
                    bracketNum--;
            }
        }
        return res;
    }
};
// leetcode的答案 stack的解法
// https://discuss.leetcode.com/topic/54904/c-non-recursive-one-pass-solution-using-stack-a-possible-implementation-of-nestedinteger/3
class Solution_0 {
  public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                stk.push(NestedInteger());
            } else if (s[i] == '-' || isdigit(s[i])) {
                int start = i;
                while (i + 1 < s.size() && isdigit(s[i + 1]))
                    i++;
                int num = stoi(s.substr(start, i - start + 1));
                NestedInteger ni(num);
                if (!stk.empty())
                    stk.top().add(ni);
                else
                    return ni;
            } else if (s[i] == ']') {
                NestedInteger temp = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    stk.top().add(temp);
                } else {
                    return temp;
                }
            }
        }
        return NestedInteger();
    }
};

// leetcode的答案 使用stack的解法
// https://discuss.leetcode.com/topic/54270/an-java-iterative-solution/2
//下面的解法通不过 oj 但是答案的java版本可以 看不出区别 以后回头看
class Solution_1 {
  public:
    NestedInteger deserialize(string s) {
        NestedInteger *res = new NestedInteger();
        if (s.empty()) {
            return *res;
        }
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger *> NestedIntegerStack;
        NestedIntegerStack.push(res);
        int start = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '[') {
                NestedInteger *temp = new NestedInteger();
                NestedIntegerStack.top()->add(*temp);
                NestedIntegerStack.push(temp);
                start = i + 1;
            } else if (s[i] == ']' || s[i] == ',') {
                if (i > start) {
                    int num = stoi(s.substr(start, i - start));
                    NestedIntegerStack.top()->add(*(new NestedInteger(num)));
                }
                start = i + 1;
                if (s[i] == ']') {
                    NestedIntegerStack.pop();
                }
            }
        }
        return *res;
    }
};