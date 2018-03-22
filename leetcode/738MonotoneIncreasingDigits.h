#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//直接看的答案 这题一开始没想出来 发现一开始题目也理解错了
// https://leetcode.com/problems/monotone-increasing-digits/discuss/109794/Simple-Python-solution-w-Explanation
// https://leetcode.com/problems/monotone-increasing-digits/discuss/109811/Simple-and-very-short-C++-solution
// https://leetcode.com/problems/monotone-increasing-digits/discuss/109788/Simple-and-very-short-Java-solution
class Solution {
  public:
    int monotoneIncreasingDigits(int N) {
        string n_str = to_string(N);
        int m = n_str.size(), marker = m;
        for (int i = m - 1; i > 0; i--) {
            if (n_str[i] < n_str[i - 1]) { // n_str[i - 1] > n_str[i]
                marker = i;
                n_str[i - 1]--;
            }
        }
        for (int j = marker; j < m; j++) {
            n_str[j] = '9';
        }
        return stoi(n_str);
    }
};