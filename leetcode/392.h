#include <string>
using namespace std;
//第一次就写了出来 成功ac 用的时间就2分钟
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        // if (s.size() > t.size()) {
        //     return false;
        // }
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size(); j++) {
            if (s[i] == t[j]) {
                i++;
            }
        }
        return i == s.size();
    }
};

// sp大神的解法
// https://discuss.leetcode.com/topic/57151/3-lines-c
class Solution_0 {
  public:
    bool isSubsequence(string s, string t) {
        auto i = s.begin();
        for (char c : t)
            i += (*i == c);
        return i == s.end();
    }
};