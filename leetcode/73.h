#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        // map<int, int> dirctory;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirctory(m, vector<int>());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dirctory[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < dirctory.size(); i++) {
            for (int j = 0; j < dirctory[i].size(); j++) {
                setRowAndColToZero(matrix, i, dirctory[i][j]);
            }
        }
    }
    void setRowAndColToZero(vector<vector<int>> &matrix, int row, int col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[row][j] = 0;
        }
    }
};
//错误的答案，刚开始就写错了
class Solution_0 {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        map<int, int> dirctory;
        map<int, int> valueDirctory;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (dirctory.find(i) != dirctory.end())
                continue;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0 &&
                    valueDirctory.find(j) == valueDirctory.end()) {
                    dirctory[i] = 1;
                    valueDirctory[j] = 1;
                    setRowAndColToZero(matrix, i, j);
                    break;
                }
            }
        }
    }
    void setRowAndColToZero(vector<vector<int>> &matrix, int row, int col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[row][j] = 0;
        }
    }
};

class Solution_1 {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirctory(m, vector<int>());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dirctory[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < dirctory.size(); i++) {
            if (dirctory[i].size() != 0)
                setRowToZero(matrix, i);
            for (int j = 0; j < dirctory[i].size(); j++) {
                setColToZero(matrix, dirctory[i][j]);
            }
        }
    }
    void setRowToZero(vector<vector<int>> &matrix, int row) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[row][j] = 0;
        }
    }
    void setColToZero(vector<vector<int>> &matrix, int col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;
        }
    }
};

void test() {
    // Solution s;
    // vector<vector<int>> matrix = {
    //     {1, 2, 3, 4}, {5, 0, 5, 2}, {8, 9, 2, 0}, {5, 7, 2, 1}};
    // s.setZeroes(matrix);

    Solution_1 s;
    vector<vector<int>> matrix = {{1}};
    s.setZeroes(matrix);
    cout<<matrix[0][0]<<endl;
}