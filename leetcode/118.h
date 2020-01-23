#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answers;
        for (int i = 0; i < numRows; i++) {
            vector<int> an(i + 1, 1);
            for (int j = 1; j < i; j++) {
                an[j] = answers[i - 1][j] + answers[i - 1][j - 1];
            }
            answers.push_back(an);
        }
        return answers;
    }
};

// ----------二刷
class Solution_0 {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                res[j] = res[j - 1] + res[j];
            }
        }
        return res;
    }
};