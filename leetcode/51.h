#include <vector>
#include <string>
#include <cmath>
using namespace std;
//自己的答案，Your runtime beats 34.07 % of cpp submissions,6ms
class Solution {
  public:
    vector<vector<string> > answers;
    int *a;
    vector<vector<string> > solveNQueens(int n) {
        a = new int[n]();
        vector<string> answer(n, string(n, '.'));
        Backtrack(answer, 0);
        return answers;
    }
    void Backtrack(vector<string> &answer, int deep) {
        if (deep >= answer.size()) {
            answers.push_back(answer);
            return;
        } else {
            for (int j = 0; j < answer[deep].size(); j++) {
                answer[deep][j] = 'Q';
                a[deep] = j;
                if (Isvalid(deep))
                    Backtrack(answer, deep + 1);
                answer[deep][j] = '.';
            }
        }
    }
    bool Isvalid(int k) {
        for (int i = 0; i < k; i++) {
            if (abs(k - i) == abs(a[i] - a[k]) || a[i] == a[k])
                return false;
        }
        return true;
    }
};
//稍微修改版答案,Your runtime beats 71.03 % of cpp submissions,3ms
class Solution_0 {
  public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > answers;
        vector<int> a(n, 0);// record the Q's position of column of the every row
        vector<string> answer(n, string(n, '.'));
        Backtrack(answers, answer, a, 0);
        return answers;
    }
    void Backtrack(vector<vector<string> > &answers, vector<string> &answer,
                   vector<int> &a, int deep) {
        if (deep >= answer.size()) {
            answers.push_back(answer);
            return;
        } else {
            for (int j = 0; j < answer[deep].size(); j++) {
                a[deep] = j;
                if (Isvalid(a, deep)) {
                    answer[deep][j] = 'Q';
                    Backtrack(answers, answer, a, deep + 1);
                    answer[deep][j] = '.';
                }
            }
        }
    }
     // check the validity of each position
    bool Isvalid(vector<int> &a, int k) {
        for (int i = 0; i < k; i++) {
            if (abs(k - i) == abs(a[i] - a[k]) || a[i] == a[k])
                return false;
        }
        return true;
    }
};