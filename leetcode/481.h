#include <algorithm>
#include <string>
using namespace std;
//就是寻找规律的题目 知道规律就非常的好写
class Solution {
  public:
    int magicalString(int n) {
        string s = "122";
        int pos = 2;
        while (s.size() < n) {
            s += string(s[pos++] - '0', s.back() == '1' ? '2' : '1');
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};

// leetcode 的答案 相当于上面的升级版 sp大神写的
// https://discuss.leetcode.com/topic/74637/short-c
class Solution_0 {
  public:
    int magicalString(int n) {
        string S = "122";
        int i = 2;
        while (S.size() < n)
            S += string(S[i++] - '0', S.back() ^ 3);
        return count(S.begin(), S.begin() + n, '1');
    }
};