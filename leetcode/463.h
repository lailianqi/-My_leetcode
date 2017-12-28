#include <vector>
using namespace std;
// leetcode的答案 用的数学的图形的分析
// https://discuss.leetcode.com/topic/68786/clear-and-easy-java-solution/4?page=1
class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int islands = 0, neighbors = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i < grid.size() - 1 && grid[i + 1][j] == 1)
                        neighbors++; // count down neighbours
                    if (j < grid[i].size() - 1 && grid[i][j + 1] == 1)
                        neighbors++; // count right neighbours
                }
            }
        }
        return islands * 4 - neighbors * 2;
    }
};

// sp大神的解法
// https://discuss.leetcode.com/topic/68778/short-python/3?page=1