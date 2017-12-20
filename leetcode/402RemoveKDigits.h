#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
//一次性过了 完全是自己的思路 非常好的题目
// 321题 类似
// leetcode上面和这个相同的思路
// https://discuss.leetcode.com/topic/59646/straightforward-java-solution-using-stack
class Solution {
  public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }
        stack<char> charStack;
        int m = num.size(), n = num.size() - k;
        for (int i = 0; i < num.size(); i++) {
            while (charStack.size() + m - i > n && !charStack.empty() &&
                   charStack.top() > num[i]) {
                charStack.pop();
            }
            if (charStack.size() < n) {
                charStack.push(num[i]);
            }
        }
        string res;
        while (!charStack.empty()) {
            res.push_back(charStack.top());
            charStack.pop();
        }
        reverse(res.begin(), res.end());
        while (res.size() > 1 && *res.begin() == '0') {
            res.erase(res.begin());
        }
        return res;
    }
};

//下面是leetcode的解法  用的是数组 算是上面解法的另外一种变通
//写的非常的好
// https://discuss.leetcode.com/topic/59412/a-greedy-method-using-stack-o-n-time-and-o-n-space
class Solution_0 {
  public:
    string removeKdigits(string num, int k) {
        int digitNum = num.size() - k, top = 0;
        vector<char> stk(num.size());
        for (int i = 0; i < num.size(); i++) {
            while (top > 0 && stk[top - 1] > num[i] && k > 0) {
                top--;
                k--;
            }
            stk[top++] = num[i];
        }
        int index = 0;
        while (index < digitNum && stk[index] == '0') {
            index++;
        }
        return index == digitNum ? "0" : string(stk.begin() + index,
                                                stk.begin() + digitNum);
    }
};