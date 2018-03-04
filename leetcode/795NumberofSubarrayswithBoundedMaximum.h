#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 74周周赛 未参加
// 这题知道是用的双指针 就是没写出来 所以直接看的答案
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117616/C++-O(n)-less10-lines
class Solution {
  public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
        int result = 0, left = -1, right = -1, m = A.size();
        for (int i = 0; i < m; i++) {
            if (A[i] > R) {
                left = i;
            }
            if (A[i] >= L) {
                right = i;
            }
            result += right - left;
        }
        return result;
    }
};
// 来自LeetCode的答案  最常规的解法 最容易懂得解法
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117595/Short-Java-O(n)-Solution
class Solution_0 {
  public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
        int res = 0, m = A.size(), counter = 0;
        for (int i = 0, j = -1; i < m; i++) {
            if (A[i] >= L && A[i] <= R) {
                res += i - j;
                counter = i - j;
            } else if (A[i] < L) {
                res += counter;
            } else {
                j = i;
                counter = 0;
            }
        }
        return res;
    }
};

//上面的改写版 加上自己原来的第一种思路
class Solution_1 {
  public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
        int res = 0, m = A.size(), counter = 0;
        for (int i = 0, j = -1; i < m; i++) {
            while (i < m && A[i] >= L && A[i] <= R) {
                res += i - j;
                counter = i - j;
                i++;
            }
            if (i == m) {
                break;
            }
            if (A[i] < L) {
                res += counter;
            } else {
                j = i;
                counter = 0;
            }
        }
        return res;
    }
};