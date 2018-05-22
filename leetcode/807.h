#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 一次ac
// leetcode上类似的解法
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/discuss/120681/Easy-and-Concise-Solution-C++JavaPython
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/discuss/120677/C++-Straightforward-O(m*n)-time
class Solution {
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int height = min(rows[i], cols[j]);
                if (grid[i][j] < height) {
                    res += height - grid[i][j];
                }
            }
        }
        return res;
    }
};