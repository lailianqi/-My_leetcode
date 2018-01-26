#include <algorithm>
#include <string>
using namespace std;
// 自己的第一种写法 成功ac
// LeetCode上差不多思想的答案 但是没这个写的好
// https://discuss.leetcode.com/topic/82626/java-concise-solution
// https://discuss.leetcode.com/topic/82627/c-java-clean-code
// https://discuss.leetcode.com/topic/82596/python-straightforward-with-explanation
// 这个链接是一模一样的答案
// https://discuss.leetcode.com/topic/82652/one-line-c
class Solution {
  public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, (int)s.size()));
        }
        return s;
    }
};
