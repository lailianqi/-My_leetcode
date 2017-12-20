#include <vector>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;
// 写不来
// 这道题目非常的难 lower的典型的应用
// https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references
// https://www.cnblogs.com/zhoudayang/p/5679496.html

//下面是我照着leetcode答案改的答案 居然和leetcode的另一个一个答案完全一样
// https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references/45?page=3
class Solution {
  public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for (int left = 0; left < col; left++) {
            vector<int> sums(row, 0);
            for (int right = left; right < col; right++) {
                for (int i = 0; i < row; i++) {
                    sums[i] += matrix[i][right];
                }

                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (auto s : sums) {
                    curSum += s;
                    auto it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) {
                        res = max(res, curSum - *it);
                    }
                    accuSet.insert(curSum);
                }
            }
        }
        return res;
    }
};