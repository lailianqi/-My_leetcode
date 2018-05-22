#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 第一次没写出来 但是这题自己绝对有能力写出来
// 参考了leetcode的答案
// https://leetcode.com/problems/expressive-words/discuss/121741/Short-straight-forward-C++-solution-two-pointers-one-pass-scan
class Solution {
  public:
    int expressiveWords(string S, vector<string> &words) {
        int res = 0;
        for (auto &e : words) {
            if (e.size() <= S.size()) {
                int i = 0, j = 0;
                for (; j < S.size(); j++) { // 这种解法可能越界
                    if (e[i] == S[j]) {
                        i++;
                    } else if (j > 0 && S[j] == S[j - 1] && j + 1 < S.size() &&
                               S[j] == S[j + 1]) {
                        j++;
                    } else if (!(j > 1 && S[j] == S[j - 1] &&
                                 S[j] == S[j - 2])) {
                        break;
                    }
                }
                if (i == e.size() && j == S.size()) {
                    res++;
                }
            }
        }
        return res;
    }
};

// leetcode的第二种解法 这种解法才应该是正确的
class Solution_0 {
  public:
    int expressiveWords(string S, vector<string> &words) {
        int res = 0;
        for (auto &e : words) {
            if (check(S, e)) {
                res++;
            }
        }
        return res;
    }
    bool check(string &S, string &w) {
        int i = 0, j = 0, n = S.size(), m = w.size();
        while (i < n && j < m) {
            while (i < n && j < m && S[i] == w[j]) {
                i++;
                j++;
            }
            if (i == n && j == m) {
                return true;
            }
            while (i > 0 && i < n && S[i] == S[i - 1]) {
                i++;
            }
            if (i < 3 || S[i - 1] != S[i - 2] || S[i - 2] != S[i - 3]) {
                return false;
            }
        }
        return i == n && j == m;
    }
};

void test() {
    Solution s;
    string str = "heeellooo";
    vector<string> vv = {"hello", "hi", "helo"};
    s.expressiveWords(str, vv);
}