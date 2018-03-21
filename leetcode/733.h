#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac
// LeetCode的解法和我的这种解法一模一样
// https://leetcode.com/problems/flood-fill/discuss/109604/Easy-Python-DFS-(no-need-for-visited)!!!
// https://leetcode.com/problems/flood-fill/discuss/109584/Java-9-liner-DFS
// https://leetcode.com/problems/flood-fill/discuss/109613/JavaC++-Clean-Code
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int orginColor = image[sr][sc];
        if (orginColor != newColor) {
            helper(image, sr, sc, newColor, orginColor);
        }
        return image;
    }
    void helper(vector<vector<int>> &image, int sr, int sc, int newColor,
                int orginColor) {
        int m = image.size(), n = image[0].size();
        if (sr < 0 || sr >= m || sc < 0 || sc >= n ||
            image[sr][sc] != orginColor) {
            return;
        }
        image[sr][sc] = newColor;
        for (int i = 0; i < direction.size(); i++) {
            helper(image, sr + direction[i][0], sc + direction[i][1], newColor,
                   orginColor);
        }
    }

  private:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};