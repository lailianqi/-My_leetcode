#include <string>
using namespace std;
//这道题挺简单的  下面是自己的第一种写法
//自己的解法和leetcode的最佳答案基本上一模一样 下面是leetcode的链接
// https://discuss.leetcode.com/topic/70642/clean-java-solution-o-n
class Solution {
  public:
    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i == 0 || (i > 0 && s[i - 1] == ' ')) && s[i] != ' ') {
                res++;
            }
        }
        return res;
    }
};

// sp大神还有一行的解法
// https://discuss.leetcode.com/topic/70736/one-liners