#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 这题没写出来  确实没想到可以这么做
// 来自LeetCode的答案
// https://leetcode.com/problems/beautiful-arrangement-ii/discuss/106948/C++-Java-Clean-Code-4-liner
// https://leetcode.com/problems/beautiful-arrangement-ii/discuss/106965/Python-Straightforward-with-Explanation

class Solution {
  public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j;) {
            res.push_back(k > 1 ? (k-- % 2 ? i++ : j--) : i++);
        }
        return res;
    }
};

// 还有一种超吊的python的解法
// https://leetcode.com/problems/beautiful-arrangement-ii/discuss/106950/3-Lines-Python