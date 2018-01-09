#include <string>
#include <vector>
#include <iostream>
using namespace std;
// leetcode 困难题  完全写不出来 leetcode论坛都没有找到正确的答案
// 下面是错误答案的链接
// https://discuss.leetcode.com/topic/79820/short-java-solution-beats-98
class Solution {
  public:
    int findMinStep(string board, string hand) {
        vector<int> dir(26, 0);
        for (int i = 0; i < hand.size(); i++) {
            dir[hand[i] - 'A']++;
        }
        board = board + "#";
        int res = helper(board, dir);
        return res == 6 ? -1 : res;
    }
    int helper(string &s, vector<int> &dir) {
        s = removeConsecutive(s);
        if (s == "#") {
            return 0;
        }
        int res = 6, need = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] != s[j]) {
                need = 3 - (i - j);
                if (dir[s[i] - 'A'] >= need) {
                    dir[s[i] - 'A'] -= need;
                    string temp = s.substr(0, j) + s.substr(i);
                    res = min(res, need + helper(temp, dir));
                    dir[s[i] - 'A'] += need;
                }
                j = i;
            }
        }
        return res;
    }
    string removeConsecutive(string &s) {
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] != s[j]) {
                if (i - j >= 3) {
                    string temp = s.substr(0, j) + s.substr(i);
                    return removeConsecutive(temp);
                }
                j = i;
            }
        }
        return s;
    }
};

//终于找到可以通过测试的答案了 leetcode的链接  但是写成c++还是过不去 蛋疼
// https://discuss.leetcode.com/topic/75434/recursive-java-solution
class Solution_0 {
  public:
    int findMinStep(string board, string hand) {
        vector<int> dir(26, 0);
        for (int i = 0; i < hand.size(); i++) {
            dir[hand[i] - 'A']++;
        }
        return helper(board, dir);
    }
    int helper(string &s, vector<int> &dir) {
        s = removeConsecutive(s);
        if (s.empty()) {
            return 0;
        }
        if (empty(dir))
            return -1;
        int res = INT_MAX, need = 0;
        for (int i = 0; i < s.size(); i++) {
            need++;
            if (i == (int)s.size() - 1 || s[i] != s[i + 1]) {
                int miss = 3 - need;
                if (dir[s[i] - 'A'] >= miss) {
                    dir[s[i] - 'A'] -= miss;
                    string temp = s.substr(0, i - need + 1) + s.substr(i + 1);
                    int smallerfind = helper(temp, dir);
                    if (smallerfind != -1) {
                        res = min(res, miss + smallerfind);
                    }
                    dir[s[i] - 'A'] += miss;
                }
                need = 0;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    string removeConsecutive(string &s) {
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] != s[j] || i == (int)s.size() - 1) {
                if (i - j >= 3) {
                    string temp = s.substr(0, j) + s.substr(i);
                    return removeConsecutive(temp);
                }
                j = i;
            }
        }
        return s;
    }
    bool empty(vector<int> &dir) {
        for (int val : dir) {
            if (val > 0)
                return false;
        }
        return true;
    }
};
void test() {
    Solution s;
    string s1 = "R", s2 = "RR";
    s.findMinStep(s1, s2);
}