#include <vector>
using namespace std;
//超内存了，这个方案不行
class Solution {
  public:
    bool canWinNim(int n) {
        vector<bool> visit(n, false);
        vector<bool> results(n, false);
        return helper(n, visit, results);
    }
    bool helper(int n, vector<bool> &visit, vector<bool> &results) {
        if (visit[n - 1]) {
            return results[n - 1];
        }
        visit[n - 1] = true;
        if (n == 1 || n == 2 || n == 3) {
            results[n - 1] = true;
            return true;
        }
        bool result =
            (!helper(n - 3, visit, results) || !helper(n - 2, visit, results) ||
             !helper(n - 1, visit, results));
        results[n - 1] = result;
        return result;
    }
};

// leetcode的答案
// https://discuss.leetcode.com/topic/27109/one-line-o-1-solution-and-explanation
class Solution_0 {
    bool canWinNim(int n) { return n % 4; }
};