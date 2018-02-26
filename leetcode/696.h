#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac
class Solution {
  public:
    int countBinarySubstrings(string s) {
        int res = 0, m = s.size();
        for (int i = 0; i < m - 1; i++) {
            if (s[i] != s[i + 1]) {
                res += findBinarySubstrings(s, i);
            }
        }
        return res;
    }
    int findBinarySubstrings(string &s, int index) {
        int res = 0;
        for (int i = index, j = index + 1; i >= 0 && j < s.size(); i--, j++) {
            if (s[i] == s[index] && s[j] == s[index + 1]) {
                res++;
            } else {
                return res;
            }
        }
        return res;
    }
};

// LeetCode的答案 写的非常的好
// https://leetcode.com/problems/count-binary-substrings/discuss/108600/Java-O(n)-Time-O(1)-Space
class Solution_1 {
  public:
    int countBinarySubstrings(string s) {
        int prevRunLength = 0, curRunLength = 1, res = 0, m = s.size();
        for (int i = 1; i < m; i++) {
            if (s[i] == s[i - 1]) {
                curRunLength++;
            } else {
                prevRunLength = curRunLength;
                curRunLength = 1;
            }
            if (prevRunLength >= curRunLength)
                res++;
        }
        return res;
    }
};

// python的写法 写的非常的好
// https://leetcode.com/problems/count-binary-substrings/discuss/108625/Python-easy-and-concise-solution-(only-2-lines)
// def countBinarySubstrings(self, s):
//         s = map(len, s.replace('01', '0 1').replace('10', '1 0').split())
//         return sum(min(a, b) for a, b in zip(s, s[1:]))

// https://leetcode.com/problems/count-binary-substrings/discuss/108604/1-liners
// def countBinarySubstrings(self, s):
//     lengths = map(len, re.findall('0+|1+', s))
//     return sum(map(min, lengths[:-1], lengths[1:]))

// 这个方法不是很懂 正则表达式没看懂
// def countBinarySubstrings(self, s):
//     return sum(min(map(len, pair)) for pair in
//     re.findall('(0+|1+)(?=(0+|1*))', s))
void test() {
    Solution s;
    s.countBinarySubstrings("1010001");
}