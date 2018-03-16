#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
class Solution {
  public:
    bool rotateString(string A, string B) {
        int m = A.size(), n = B.size();
        if (m != n) {
            return false;
        }
        for (int i = 1; i <= m; i++) {
            if (A.substr(0, i) == B.substr(m - i) &&
                A.substr(i) == B.substr(0, m - i)) {
                return true;
            }
        }
        return false;
    }
};

// LeetCode的答案 写的比上面我的第一中方案好
// https://leetcode.com/problems/rotate-string/discuss/118696/C++-Java-Python-1-Line-Solution?page=1
class Solution_0 {
  public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};

void test() {
    Solution s;
    s.rotateString("abcde", "cdeab");
}