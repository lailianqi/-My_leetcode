#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题第一次没写出来 但是这题的技巧一定要会
// 来自LeetCode的答案
// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/discuss/106977/Java-solution-binary-search
// http://blog.csdn.net/he1533/article/details/77774526
// http://blog.csdn.net/zjucor/article/details/77688556
class Solution {
  public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int c = count(mid, m, n);
            if (c < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int count(int val, int m, int n) {
        int res = 0;
        for (int i = 1; i <= m; i++) {
            res += min(val / i, n);
        }
        return res;
    }
};