#include <vector>
#include <climits>
using namespace std;
//结合84的解法
class Solution {
  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n + 1, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            vector<int> stack;
            for (int j = 0; j <= n; j++) {
                if (j < n) {
                    if (matrix[i][j] == '1') {
                        heights[j]++;
                    } else {
                        heights[j] = 0;
                    }
                }
                while (!stack.empty() && heights[stack.back()] > heights[j]) {
                    int height = heights[stack.back()];
                    stack.pop_back();
                    int temp = stack.empty() ? -1 : stack.back();
                    maxArea = max(maxArea, height * (j - 1 - temp));
                }
                stack.push_back(j);
            }
        }
        return maxArea;
    }
};
// dp的写法
class Solution_0 {
  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), heights(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else {
                    heights[j] = 0;
                }
            }
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            for (int j = 0; j < n; j++)
                maxArea = max(maxArea, (right[j] - left[j]) * heights[j]);
        }
        return maxArea;
    }
};