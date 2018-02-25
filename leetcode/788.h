#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 73周周赛 未参加
// 自己的第一种方案 成功ac
// leetcode类似的答案
// https://leetcode.com/problems/rotated-digits/discuss/116539/Python-Solution-(using-String)
// https://leetcode.com/problems/rotated-digits/discuss/116529/C++-solution-using-to_string-find
class Solution {
  public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++) {
            string s = to_string(i);
            if (s.find("3") != string::npos || s.find("4") != string::npos ||
                s.find("7") != string::npos) {
                continue;
            }
            if (s.find("2") != string::npos || s.find("5") != string::npos ||
                s.find("6") != string::npos || s.find("9") != string::npos) {
                res++;
            }
        }
        return res;
    }
};

// LeetCode python的解法 写的非常的好
// https://leetcode.com/problems/rotated-digits/discuss/116530/Easy-Understand-Solution

// def rotatedDigits(self, N):
//         def isGood(x):
//             s1 = set([1, 8, 0])
//             s2 = set([1, 8, 0, 6, 9, 2, 5])
//             s = set([int(i) for i in str(x)])
//             return s.issubset(s2) and not s.issubset(s1)
//         return sum(isGood(i) for i in range(N + 1))

// https://leetcode.com/problems/rotated-digits/discuss/116539/Python-Solution-(using-String)
// class Solution(object):
//     def rotatedDigits(self, N):
//         counts = 0
//         for num in range(1, N+1):
//             number = str(num)
//             if '3' in number or '7' in number or '4' in number: # This will
//             be an invalid number upon rotation
//                 continue
//             if '2' in number or '5' in number or '6' in number or '9' in
//             number:
//                 counts += 1
//         return counts