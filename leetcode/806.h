#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 一次ac
// 和leetcode上的解法 思想其实差不多
// https://leetcode.com/problems/number-of-lines-to-write-string/discuss/120666/Easy-Solution-6-lines-C++JavaPython
class Solution {
  public:
    vector<int> numberOfLines(vector<int> &widths, string S) {
        int m = S.size(), sum_width = 0, count_line = 0;
        for (int i = 0; i < m; i++) {
            sum_width += widths[S[i] - 'a'];
            if (sum_width >= 100) {
                count_line++;
                sum_width -= 100;
                if (sum_width > 0) {
                    sum_width = 0;
                    i--;
                }
            }
        }
        return {count_line + 1, sum_width};
    }
};

// leetcode的解法的代码写法
// https://leetcode.com/problems/number-of-lines-to-write-string/discuss/120666/Easy-Solution-6-lines-C++JavaPython
class Solution_0 {
  public:
    vector<int> numberOfLines(vector<int> &widths, string S) {
        int m = S.size(), sum_width = 0, count_line = 0;
        for (int i = 0; i < m; i++) {
            count_line = sum_width + widths[S[i] - 'a'] > 100 ? count_line + 1
                                                              : count_line;
            sum_width = sum_width + widths[S[i] - 'a'] > 100
                            ? widths[S[i] - 'a']
                            : sum_width + widths[S[i] - 'a'];
        }
        return {count_line + 1, sum_width};
    }
};

// leetcode上面的解法
// https://leetcode.com/problems/number-of-lines-to-write-string/discuss/120668/C++-Straightforward
class Solution_1 {
  public:
    vector<int> numberOfLines(vector<int> &widths, string S) {
        int lines = 1, occupied_width = 0, len = S.length();
        for (int i = 0; i < len; i++) {
            if ((occupied_width + widths[S[i] - 'a']) > 100) {
                lines++;
                occupied_width = 0;
            }
            occupied_width += widths[S[i] - 'a'];
        }
        return {lines, occupied_width};
    }
};