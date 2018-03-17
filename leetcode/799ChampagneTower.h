#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 这题没写出来  直接看的答案 其实这题并不难
// 来自LeetCode的答案
// https://leetcode.com/problems/champagne-tower/discuss/118660/20ms-C++-Easy-understand-solution
class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> result(
            query_row + 2,
            vector<double>(query_row + 2, 0)); // 因为给的是下标 所以+2
        result[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] > 1) {
                    result[i + 1][j] += (result[i][j] - 1) / 2;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};

// 上面的空间的优化版
// https://leetcode.com/problems/champagne-tower/discuss/118692/9ms-5-Lines-Code-C++Java
// https://leetcode.com/problems/champagne-tower/discuss/118711/O(1)-space-solution-C++JavaPython
class Solution_0 {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> result(query_row + 1, 0);
        result[0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = i; j >= 0; j--) {
                result[j + 1] += (result[j] = max(0.0, (result[j] - 1) / 2));
            }
        }
        return min(result[query_glass], 1.0);
    }
};

void test() {
    Solution_0 s;
    s.champagneTower(1, 1, 0);
}