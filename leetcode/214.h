#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//这题一开始是真的不会 kmp 所以没有写出来
// https://discuss.leetcode.com/topic/14526/c-8-ms-kmp-based-o-n-time-o-n-memory-solution?page=1
class Solution {
  public:
    string shortestPalindrome(string s) {
        int m = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string ss = s + "#" + rev;
        vector<int> next(ss.size() + 1, 0);
        getNext(ss, next);
        return rev.substr(0, m - next[ss.size()]) + s;
    }
    void getNext(string s, vector<int> &next) {
        int m = s.size();
        next[0] = -1;
        for (int i = 0; i < m; i++) {
            int k = next[i];
            while (k != -1 && s[k] != s[i])
                k = next[k];
            next[i + 1] = k + 1;
        }
    }
    void GetNext1(string p, vector<int> &next) {
        int m = p.size(), k = -1, j = 0;
        next[0] = -1;
        while (j < m - 1) {
            if (k == -1 || p[j] == p[k]) {
                k++, j++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
};

class Solution_0 {
  public:
    string shortestPalindrome(string s) {
        int m = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string ss = s + "#" + rev;
        vector<int> next(ss.size() + 1, 0);
        getNext(ss, next);
        return rev.substr(0, m - next[ss.size()]) + s;
    }

    void getNext(string s, vector<int> &next) {
        int m = s.size();
        next[0] = -1;
        for (int i = 0; i < m; i++) {
            int k = next[i];
            while (k != -1 && s[i] != s[k]) {
                k = next[k];
            }
            next[i + 1] = k + 1;
        }
    }
};