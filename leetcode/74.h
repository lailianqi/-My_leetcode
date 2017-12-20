#include <vector>
#include <algorithm>
using namespace std;

//自己写的方法，运行效率一般
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        int i = 0;
        while (i < m && matrix[i][0] <= target)
            i++;
        i--;
        if (i < 0)
            return false;
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }
};
//直接转换为二分查找
class Solution_0 {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            } else if (matrix[mid / n][mid % n] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

class Solution_1 {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

void test() {
    Solution_0 s;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    s.searchMatrix(matrix, 3);
}