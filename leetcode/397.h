#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;
//自己的第一种解法 通过了ac 但是这种解法代码不够简洁
class Solution {
  public:
    int integerReplacement(int n) {
        unordered_map<int, int> dir;
        return helper(n, dir);
    }
    int helper(int n, unordered_map<int, int> &dir) {
        if (n == 1) {
            return 0;
        }
        if (n == INT_MAX)
            return 32;
        if (dir.find(n) != dir.end()) {
            return dir[n];
        }
        int result = 0;
        if (n & 1) {
            result = min(helper(n - 1, dir), helper(n + 1, dir)) + 1;
        } else {
            result = helper(n / 2, dir) + 1;
        }
        dir[n] = result;
        return result;
    }
};
class Solution_0 {
  public:
    int integerReplacement(int n) { return helper(n); }
    int helper(int n) {
        if (n == 1) {
            return 0;
        }
        if (n == INT_MAX)
            return 32;
        int result = 0;
        if (n & 1) {
            result = min(helper(n - 1), helper(n + 1)) + 1;
        } else {
            result = helper(n / 2) + 1;
        }
        return result;
    }
};
// leetcode的解法 非常的牛逼 分析的很透彻
// https://discuss.leetcode.com/topic/58334/a-couple-of-java-solutions-with-explanations/2
class Solution_1 {
  public:
    int integerReplacement(int n) {
        if (n == INT_MAX)
            return 32;
        int res = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                n >>= 1;
            } else if (n == 3 || ((n >> 1) & 1) == 0) {
                n--;
            } else {
                n++;
            }
            res++;
        }
        return res;
    }
};