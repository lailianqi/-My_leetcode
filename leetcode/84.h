#include <vector>
#include <climits>
using namespace std;
//最简单的解法 当是时间复杂度太高O(n2)，通不过测试    95 / 96 test cases passed.
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int m = heights.size();
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            int index = i;
            int area = 0;
            for (int j = index; heights[j] >= heights[index] && j >= 0; j--) {
                area += heights[index];
            }
            for (int j = index + 1; heights[j] >= heights[index] && j < m;
                 j++) {
                area += heights[index];
            }
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
//参照leetcode的写法
class Solution_0 {
  public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> stack;
        int maxArea = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                int height = heights[stack.back()];
                stack.pop_back();
                int temp = stack.empty() ? -1 : stack.back();
                maxArea = max(maxArea, height * (i - 1 - temp));
            }
            stack.push_back(i);
        }
        return maxArea;
    }
};
// Leetcoded的dp写法
class Solution_1 {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int m = heights.size();
        int p, ans = 0;
        vector<int> left(m, 0), right(m, m);
        for (int i = 1; i < m; i++) {
            p = i - 1;
            while (p >= 0 && heights[i] <= heights[p]) {
                p = left[p] - 1;
            }
            left[i] = p + 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            p = i + 1;
            while (p < m && heights[i] <= heights[p])
                p = right[p];
            right[i] = p;
        }
        for (int i = 0; i < m; ++i)
            ans = max(ans, heights[i] * (right[i] - left[i]));
        return ans;
    }
};