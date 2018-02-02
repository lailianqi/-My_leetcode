#include <string>
#include <unordered_map>
using namespace std;
// 自己的第一种解法 成功ac
class Solution {
  public:
    bool checkRecord(string s) {
        unordered_map<char, int> dir;
        for (int i = 0; i < s.size(); i++) {
            dir[s[i]]++;
            if (dir['A'] > 1 ||
                (i >= 2 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')) {
                return false;
            }
        }
        return true;
    }
};

// 自己不用map的写法
// LeetCode上面相似的答案
// https://discuss.leetcode.com/topic/86584/c-very-simple-solution
class Solution_0 {
  public:
    bool checkRecord(string s) {
        int aCounter = 0, lCounter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                aCounter++;
            }
            if (s[i] == 'L') {
                lCounter++;
            } else {
                lCounter = 0;
            }
            if (aCounter > 1 || lCounter > 2) {
                return false;
            }
        }
        return true;
    }
};
// 最简单的办法还是用正则表达式 但是我不会 来自LeetCode的答案
// https://discuss.leetcode.com/topic/86466/java-1-liner
// https://discuss.leetcode.com/topic/86534/tiny-ruby-short-python-java-c
// 或者字符串匹配
// https://discuss.leetcode.com/topic/86559/java-simple-without-regex-3-lines