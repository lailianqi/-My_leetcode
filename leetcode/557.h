#include <string>
using namespace std;
// 自己的第一种方案 成功ac
// LeetCode的答案 和我的方案同样的思想 不同的写法
// https://discuss.leetcode.com/topic/85784/c-java-clean-code
class Solution {
  public:
    string reverseWords(string s) {
        int left = 0, right = 0, m = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (i == 0 || s[i - 1] == ' ') {
                    left = i;
                }
                if (i == m - 1 || s[i + 1] == ' ') {
                    right = i;
                    reverse(s.begin() + left, s.begin() + right + 1);
                }
            }
        }
        return s;
    }
};

// pythoon 的写法来自LeetCode 的sp大神
// https://discuss.leetcode.com/topic/85882/1-line-ruby-python
