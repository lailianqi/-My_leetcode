#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题没写出来 字符串匹配的都不怎么会
// 来自LeetCode的题解
// https://leetcode.com/articles/repeated-string-match/
class Solution {
  public:
    int repeatedStringMatch(string A, string B) {
        int i = 1;
        string temp = A;
        for (; temp.size() < B.size(); i++) {
            temp += A;
        }
        if (temp.find(B) != -1) {
            return i;
        }
        temp += A;
        if (temp.find(B) != -1) {
            return ++i;
        }
        return -1;
    }
};
// LeetCode答案比上面的官方题解更好的解法
// https://leetcode.com/problems/repeated-string-match/discuss/108118/C++Java-Clean-Code
class Solution_0 {
  public:
    int repeatedStringMatch(string A, string B) {
        string as = A;
        for (int rep = 1; rep <= B.length() / A.length() + 2; rep++, as += A)
            if (as.find(B) != string::npos)
                return rep;
        return -1;
    }
};

// 第二种解法 来自LeetCode
// https://leetcode.com/problems/repeated-string-match/discuss/108084/C++-4-lines-O(m-*-n)-or-O(1)-and-7-lines-KMP-O(m-+-n)-or-O(n)
class Solution_1 {
  public:
    int repeatedStringMatch(string A, string B) {
        for (auto i = 0, j = 0; i < A.size(); ++i) {
            for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j)
                ;
            if (j == B.size())
                return (i + j) / A.size() + ((i + j) % A.size() != 0 ? 1 : 0);
        }
        return -1;
    }
    //这个是上面的改进版 用kmp优化
    int repeatedStringMatch1(string a, string b) {
        vector<int> prefTable(b.size() + 1); // 1-based to avoid extra checks.
        for (auto sp = 1, pp = 0; sp < b.size(); prefTable[++sp] = pp) {
            pp = b[pp] == b[sp] ? pp + 1 : prefTable[pp];
        }
        for (auto i = 0, j = 0; i < a.size();
             i += max(1, j - prefTable[j]), j = prefTable[j]) {
            while (j < b.size() && a[(i + j) % a.size()] == b[j])
                ++j;
            if (j == b.size())
                return (i + j) / a.size() + ((i + j) % a.size() != 0 ? 1 : 0);
        }
        return -1;
    }
};