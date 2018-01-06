#include <vector>
#include <algorithm>
using namespace std;
//这题比较麻烦 主要是写出它的绕圈规律 所以直接看的答案 下面是答案的链接
// https://discuss.leetcode.com/topic/77865/concise-java-solution?page=1
// https://discuss.leetcode.com/topic/77865/concise-java-solution/6?page=1
class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size(),
            totalNum = m * n;
        int row = 0, col = 0, d = 1;
        vector<int> res(totalNum, 0);
        for (int i = 0; i < totalNum; i++) {
            res[i] = matrix[row][col];
            row = row - d, col = col + d;
            //前两个和后两个的顺序不能变 要不然会发生错误
            //主要是对角线的两个角的原因（左下角和右上角） 画图分析可知
            if (row >= m) {
                row = m - 1;
                col = col + 2;
                d = -d;
            }
            if (col >= n) {
                col = n - 1;
                row = row + 2;
                d = -d;
            }
            if (row < 0) {
                row = 0;
                d = -d;
            }
            if (col < 0) {
                col = 0;
                d = -d;
            }
        }
        return res;
    }
};

// leetcode上另外一种我认可的答案 比上面的发现规律牛逼多了
// https://discuss.leetcode.com/topic/77918/c-without-paying-too-much-attention-on-direction-switch/2
class Solution_0 {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < m + n - 1; i++) {
            int begin_pos = res.size();
            for (int row = max(0, i - n + 1), col = min(i, n - 1);
                 col >= 0 && row < m; row++, col--) {
                res.push_back(matrix[row][col]);
            }
            if (i % 2 == 0)
                reverse(res.begin() + begin_pos, res.end());
        }
        return res;
    }
};
void test() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.findDiagonalOrder(matrix);
}