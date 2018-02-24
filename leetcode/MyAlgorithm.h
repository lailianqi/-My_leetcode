#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isInVaildBoardary(vector<vector<int>> &grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    if (row >= 0 && row < m && col >= 0 && col < n) {
        return true;
    }
    return false;
}